#ifndef INVENTORY_H
#define INVENTORY_H
#include "commands.h"

class Inventory : public Commands {
public:
  Inventory();
  virtual ~Inventory();

  // Methods
  virtual bool action(Movie* movie, Customer* customer);

protected:
// I don't think we need anything at all here
};
#endif