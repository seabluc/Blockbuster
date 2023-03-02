#ifndef RETURN_H
#define RETURN_H
#include "commands.h"

class Return : public Commands {
public:
  Return(int customerID, Movie* movie);
  virtual ~Return();
  
  // Methods
  // a virtual method to initiate Return 'R'

protected:
// Do we need anything here? I figured we get the actual Movie from Movie class and customerID from Customer class.
};
#endif