#include "exception_handler.h"

#include "logger_command.h"
#include "repeate_command.h"

ExceptionHandler::ExceptionHandler(QueueCommand *queue_cmd, ICommand *cmd,
                                   std::exception *ex)
    : queue_cmd_(queue_cmd), cmd_(cmd), ex_(ex) {}

ExceptionHandlerLog::ExceptionHandlerLog(QueueCommand *queue_cmd, ICommand *cmd,
                                         std::exception *ex)
    : ExceptionHandler(queue_cmd, cmd, ex) {}

void ExceptionHandlerLog::handle() {
  queue_cmd_->addCommand(new LoggerCommand(cmd_, ex_->what()));
}

ExceptionHandlerRepeate::ExceptionHandlerRepeate(QueueCommand *queue_cmd,
                                                 ICommand *cmd,
                                                 std::exception *ex)
    : ExceptionHandler(queue_cmd, cmd, ex) {}

void ExceptionHandlerRepeate::handle() {
  queue_cmd_->addCommand(new RepeateCommand(cmd_));
}

ExceptionHandlerRepeateAndLog::ExceptionHandlerRepeateAndLog(
    QueueCommand *queue_cmd, ICommand *cmd, std::exception *ex)
    : ExceptionHandler(queue_cmd, cmd, ex), is_first(false) {}

void ExceptionHandlerRepeateAndLog::handle(){
  if (is_first){
    queue_cmd_->addCommand(new RepeateCommand(cmd_));
  } else {
    queue_cmd_->addCommand(new LoggerCommand(cmd_, ex_->what()));
  }
}

// ICommand* ExceptionHandlerLog::handle(ICommand* cmd, std::exception& ex)
// {
//   try {
//     return handlers_.at(typeid(ex).name()).at(typeid(*cmd).name());
//   } catch (std::out_of_range& ex) {
//     handlers_[typeid(ex).name()][typeid(*cmd).name()] = {
//         new LoggerCommand(cmd, ex.what())};
//     return handlers_[typeid(ex).name()][typeid(*cmd).name()];
//   }
// }
