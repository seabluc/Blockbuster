#ifndef HISTORY_H
#define HISTORY_H
#include "commands.h"

class History : public Commands {
public:
  History(int customerID);
  virtual ~History();

  // Methods
  // a virtual method to initiate History 'H'

protected:
// Do we need anything here? I figured we get the actual customerID from Customer class.
};
#endif