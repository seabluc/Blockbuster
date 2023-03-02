#ifndef BORROW_H
#define BORROW_H
#include "commands.h"

class Borrow : public Commands {
public:
  Borrow(int customerID, Movie* movie); // Borrow needs customer ID and the movie to borrow.
  virtual ~Borrow();

  // Methods
  // a virtual method to initiate Borrow 'B'

protected:
// Do we need anything here? I figured we get the actual Movie from Movie class and customerID from Customer class.
};
#endif