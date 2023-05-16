#include "exception_handler.h"

#include "logger_command.h"
#include "repeate_command.h"

bool ExceptionHandlerRepeateAndLog::is_first(true);

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
    : ExceptionHandler(queue_cmd, cmd, ex) {}

void ExceptionHandlerRepeateAndLog::handle(){
  if (is_first){
    queue_cmd_->addCommand(new RepeateCommand(cmd_));
    is_first = false;
  } else {
    queue_cmd_->addCommand(new LoggerCommand(cmd_, ex_->what()));
    is_first = true;
  }
}