#pragma once

#include "state.h"

class DefaultState : public State {
 public:
  DefaultState(CommandExecutor *commamd_executor);
  virtual std::unique_ptr<State> handle() override;
};
