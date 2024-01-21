#pragma once

#include "field.h"

class GameArea : public AbstractHandler {
  public:
   GameArea(Contex *contex);

   bool Handle(Object* obj1, Object *obj2) override;

   Field* findField(Object *obj);
   void setObject(Object* obj);

  private:
   Contex* contex_;
   std::vector<std::vector<Field>> fields_;
};