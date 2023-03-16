// ----------------------------------return.h----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
// Purpose - Header file for the return command.
#ifndef RETURN_H
#define RETURN_H
#include "commands.h"
#include "../Customer/customerHashTable.h"

class Return : public Commands {
public:
  Return(int customerID, Movie* movie);
  virtual ~Return();
  
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