#pragma once

#include <amqpcpp.h>
#include <amqpcpp/libboostasio.h>

#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/strand.hpp>
#include <boost/json.hpp>
#include <boost/json/value.hpp>
#include <cstdlib>
#include <memory>

#include "type_def.h"

using UsersGame = std::map<std::string, uint64_t>;

class MessageBroker {
 public:
  MessageBroker(AMQP::Address *adress) {
    service = std::make_unique<boost::asio::io_service>(4);
    AMQP::LibBoostAsioHandler handler(*service);
    AMQP::TcpConnection connection(&handler, *adress);
    channel_create_game = std::make_unique<AMQP::TcpChannel>(&connection);
    channel_create_token = std::make_unique<AMQP::TcpChannel>(&connection);

    channel_create_game->consume("create_game")
        .onReceived([this](const AMQP::Message &message, uint64_t deliveryTag,
                           bool redelivered) {
          std::string msg_json(message.body(), message.bodySize());
          boost::json::value jv = boost::json::parse(msg_json);

          uint64_t id_game = ::rand();

          for (auto it = jv.as_array().begin(); it != jv.as_array().end();
               it++) {
            if (this->users_game.count(it->as_string().c_str())) {
              std::cerr << "User " << it->as_string() << " is playing now";
              continue;
            } else {
              this->users_game[it->as_string().c_str()] = id_game;
            }
          }
        });

    channel_create_token->consume("create_token")
        .onReceived([=](const AMQP::Message &message, uint64_t deliveryTag,
                        bool redelivered) {
          std::string msg_json(message.body(), message.bodySize());
          boost::json::value jv = boost::json::parse(msg_json);

          DataForCreateToken data;
          data.user = jv.at("user").as_string();
          data.id_game = jv.at("id_game").as_uint64();

          
        });
  }
  void run() { service->run(); }

 private:
  UsersGame users_game;
  std::unique_ptr<boost::asio::io_service> service;
  std::unique_ptr<AMQP::TcpChannel> channel_create_game;
  std::unique_ptr<AMQP::TcpChannel> channel_create_token;
};