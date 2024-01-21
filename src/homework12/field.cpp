#include "field.h"

bool Field::check_object(Object* object) {
  auto it = std::find(objects_.begin(), objects_.end(), object);
  return it != objects_.end();
}

void Field::add_object(Object* object) { objects_.push_back(object); }

void Field::remove_object(Object* object) {
  std::remove_if(objects_.begin(), objects_.end(), [object](Object* obj) {
    return obj->getProperty("id") == object->getProperty("id");
  });
}

bool Field::Handle(Object* obj1, Object *obj2) {
  if (check_object(obj1) && check_object(obj2)) {
    // здесь должна быть функция коллизии
    return true;
  }
  return false;
}
