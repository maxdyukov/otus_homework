#pragma once

#include "state.h"

class MoveToState : public State {
 public:
  MoveToState(CommandExecutor *commamd_executor);
  std::unique_ptr<State> handle() override;
};