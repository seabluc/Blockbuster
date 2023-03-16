// ------------------------------commands.h------------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
// Purpose - This header file defines the Commands class, which is a base class
// for all the commands that customers can perform on movies. Derived classes 
// will handle specific command implementations.
// ----------------------------------------------------------------------------
#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
using namespace std;
#include "../Movie/movie.h"
#include "../Customer/customer.h"

class Commands {
public:
  Commands();
  virtual~Commands();

  // Methods
  virtual bool action();
  char getCommandType() {
    return commandType;
  }
protected:
  char commandType; // 'B', 'H', 'I', 'R'
};
#endif