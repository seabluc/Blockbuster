// ------------------------------borrow.h--------------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
//
// Purpose - This file defines the Borrow class. The Borrow class is responsible
// for handling the borrow command for a specific customer and movie. It
// updates the inventory of the movie and records the transaction in the
// customer's history.
//-----------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H
#include "commands.h"
#include "../Customer/customerHashTable.h"

class Borrow : public Commands {
public:
  Borrow(int customerID, Movie* movie);
  virtual ~Borrow();

  // Methods
  virtual bool action(list<Movie*>&, CustomerHashTable&);
  Movie* getMovie() {
      return movie;
  }
protected:
  Movie* movie;
	int customerID;
};
#endif