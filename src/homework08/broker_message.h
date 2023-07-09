#pragma once

#include <amqpcpp.h>
#include <amqpcpp/libboostasio.h>

#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/strand.hpp>
#include <boost/json.hpp>
#include <boost/json/value.hpp>

#include <memory>

#include "command_executor.h"
#include "object.h"

using AllObjects = std::map<int, std::vector<Object *>>;

class MessageBroker {
 public:
  MessageBroker(AMQP::Address *adress, AllObjects *objects,
                CommandExecutor *cmd_exec)
      : objects(objects), cmd_exec(cmd_exec) {
    service = std::make_unique<boost::asio::io_service>(4);
    AMQP::LibBoostAsioHandler handler(*service);
    AMQP::TcpConnection connection(&handler, *adress);
    channel = std::make_unique<AMQP::TcpChannel>(&connection);

    auto messageCb = [this](const AMQP::Message &message, uint64_t deliveryTag,
                            bool redelivered) {
      try {
        std::string msg_json(message.body(), message.bodySize());
        boost::json::value jv = boost::json::parse(msg_json);

        TMessage msg;
        msg.id_game_ = jv.at("id_game").as_int64();
        msg.id_game_obj_ = jv.at("id_game_obj").as_int64();
        msg.id_operation_ = jv.at("id_operation").as_int64();
        msg.args_json_ = jv.at("args").as_array();

        auto inter_cmd =
            std::make_unique<InterpretCommand>(msg, this->objects, this->cmd_exec);
        inter_cmd->execute();

        channel->ack(deliveryTag);
      } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
      }
    };

    channel->consume("commands").onReceived(messageCb);
  }
  void run() { service->run(); }

 private:
  AllObjects *objects;
  CommandExecutor *cmd_exec;
  std::unique_ptr<boost::asio::io_service> service;
  std::unique_ptr<AMQP::TcpChannel> channel;
};