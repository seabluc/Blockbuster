#ifndef RETURN_H
#define RETURN_H
#include "commands.h"

class Return : public Commands {
public:
  Return(int customerID, Movie* movie);
  virtual ~Return();
  
  // Methods
  virtual bool action(Movie* movie, Customer* customer);

protected:
// Do we need anything here? I figured we get the actual Movie from Movie class and customerID from Customer class.
};
#endif