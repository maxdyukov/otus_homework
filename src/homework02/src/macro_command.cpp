#include "macro_command.h"

MacroCommand::MacroCommand(std::vector<ICommand*> commands) : commands_(commands){}

void MacroCommand::execute(){
    for(auto &it : commands_){
      it->execute();
    }
}