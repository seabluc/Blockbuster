// ------------------------------history.h-------------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// 
// Purpose - This header file defines the History class, which is a derived 
// class from Commands. The History class represents the command to display
// a customer's transaction history.
// ----------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
#include "commands.h"
#include "../Customer/customerHashTable.h"

class History : public Commands {
public:
  History(int customerID);
  virtual ~History();

  // Methods
  virtual bool action(CustomerHashTable&);
protected:
  int customerID;
};
#endif