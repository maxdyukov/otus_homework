#pragma once

#include "field.h"

class GameArea : public AbstractHandler {
  public:
   GameArea(Contex *contex);

   void Handle() override;

   Field* findField(Object *obj);
   void setObject(Object* obj);

  private:
   std::vector<std::vector<Field>> fields_;
};