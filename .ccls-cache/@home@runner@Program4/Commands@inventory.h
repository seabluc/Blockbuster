// ------------------------------inventory.h-----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// 
// Purpose - This header file defines the Inventory class, which is a derived 
// class from Commands. The Inventory class represents the command to display
// the current inventory of movies in the store.
// ----------------------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H
#include "commands.h"

class Inventory : public Commands {
public:
  Inventory();
  virtual ~Inventory();

  // Methods
  virtual bool action(list<Movie *> &comedyList, list<Movie *> &classicsList,
                      list<Movie *> &dramaList);
};
#endif