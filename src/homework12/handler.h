#pragma once

#include <memory>

#include "contex.h"

// Интерфейс обработчика
class Handler {
 public:
  virtual ~Handler() {}
  virtual Handler* SetNext(Handler* handler) = 0;
  virtual void Handle() = 0;
};

// Базовый класс обработчика
class AbstractHandler : public Handler {
 protected:
  Handler* next_handler_;
  Contex* contex_;

 public:
  AbstractHandler(Contex* contex) : next_handler_(nullptr), contex_(contex) {}

  Handler* SetNext(Handler* handler) override {
    next_handler_ = handler;
    return handler;
  }

  virtual void Handle() override {
    if (next_handler_) {
        next_handler_->Handle();
    }
  }
};