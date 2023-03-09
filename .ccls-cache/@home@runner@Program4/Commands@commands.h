#ifndef COMMANDS_H
#define COMMANDS_H
#include <iostream>
using namespace std;
#include "../Movie/movie.h"
#include "../Customer/customer.h"
// #include whatever classes that receive instantiated data after Blockbuster reads all txt files.
class Commands {
public:
  Commands();
  virtual~Commands();

  // Methods
  virtual bool action(Movie* movie, Customer* customer);
protected:
  char commandType; // 'B', 'H', 'I', 'R'
};
#endif