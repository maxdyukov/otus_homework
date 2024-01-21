#pragma once

#include <algorithm>
#include <vector>

#include "handler.h"
#include "object.h"

struct Index {
  size_t i, j;
};

class Field : public AbstractHandler {
 public:
  Field(Contex* contex, Index index) : AbstractHandler(contex), index_(index) {}

  int getI() { return index_.i; }
  int getJ() { return index_.j; }

  void add_object(Object* object);
  void remove_object(Object* object);

  bool check_object(Object* object);

  virtual bool Handle(Object* obj1, Object *obj2) override;

 protected:
  Index index_;
  std::vector<Object*> objects_;
};