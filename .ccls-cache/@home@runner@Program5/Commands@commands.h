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
  // a virtual method to initiate Actions given the right char ('B', 'H', 'I', 'R')? smth similar to css342 jolly banker

protected:
  char commandType; // 'B', 'H', 'I', 'R'
};
#endif