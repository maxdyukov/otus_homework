#include "game_area.h"

GameArea::GameArea(Contex *contex) : AbstractHandler(contex) {
  size_t x = std::any_cast<size_t>(contex_->get("area_x"));
  size_t y = std::any_cast<size_t>(contex_->get("area_y"));
  size_t width_neighborhood =
      std::any_cast<size_t>(contex_->get("width_neighborhood"));
  size_t height_neighborhood =
      std::any_cast<size_t>(contex_->get("height_neighborhood"));

  for (size_t i = 0; i < x / width_neighborhood; i++) {
    fields_.push_back({});
    for (size_t j = 0; j < y / height_neighborhood; j++) {
      fields_.at(i).push_back(Field(contex_, {i, j}));
    }
  }
}

Field *GameArea::findField(Object *obj) {
  for (auto &fieldX : fields_) {
    for (auto &field : fieldX) {
      if (field.check_object(obj)) {
        return &field;
      }
    }
  }
  return nullptr;
}

void GameArea::Handle() {
  SetNext(findField(std::any_cast<Object*>(contex_->get("findObject"))));
  AbstractHandler::Handle();
}

void GameArea::setObject(Object *obj) {
  int obj_x = obj->getProperty("x");
  int obj_y = obj->getProperty("y");

  size_t width_neighborhood =
      std::any_cast<size_t>(contex_->get("width_neighborhood"));
  size_t height_neighborhood =
      std::any_cast<size_t>(contex_->get("height_neighborhood"));

  for (size_t i = 0; i < fields_.size(); i++) {
    auto field_coord_x = i * width_neighborhood;
    for (size_t j = 0; j < fields_.at(i).size(); j++) {
      auto field_coord_y = j * height_neighborhood;
      if (field_coord_x < obj_x &&
          (field_coord_x + width_neighborhood) > obj_x &&
          field_coord_y < obj_y &&
          (field_coord_y + height_neighborhood) > obj_y) {
        fields_.at(i).at(j).add_object(obj);
          return;
      }
    }
  }
}