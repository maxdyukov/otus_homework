#include "interpret_command.h"

#include "move_command.h"
#include "rotate_command.h"

InterpretCommand::InterpretCommand(const TMessage &a_msg, AllObjects *a_objects,
                                   CommandExecutor *a_cmd_exec)
    : msg_(a_msg), game_objects_(a_objects), cmd_exec_(a_cmd_exec) {}

void InterpretCommand::execute() {
  auto objects = game_objects_->find(msg_.id_game_);
  if (objects != game_objects_->end()) {
    auto object = std::find_if(
        objects->second.begin(), objects->second.end(), [this](Object *obj) {
          return this->msg_.id_game_obj_ == obj->getProperty("id");
        });
    if (object != objects->second.end()) {
      ICommand *cmd{nullptr};
      switch (msg_.id_operation_) {
        case 1: {
          int speed = msg_.args_json_.at(0).as_int64();
          cmd = new MoveCommand((*object), speed);
          break;
        }
        case 2: {
          int speed = msg_.args_json_.at(0).as_int64();
          int angular = msg_.args_json_.at(1).as_int64();
          cmd = new RotateCommand((*object), speed, angular);
          break;
        }
      }
      cmd_exec_->addCommand(cmd);
    }
  }
}