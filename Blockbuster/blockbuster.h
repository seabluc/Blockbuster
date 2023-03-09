#ifndef BLOCKBUSTER_H
#define BLOCKBUSTER_H
#include <iostream>
#include <queue>
#include <list>
#include <cstring>
#include <fstream> // File reading
// Can probably just inherit the base classes of each file to reduce code
// #include "../Commands/borrow.h"
#include "../Commands/commands.h"
// #include "../Commands/history.h"
// #include "../Commands/inventory.h"
// #include "../Commands/return.h"
#include "../Customer/customer.h"
// #include "../Movie/classics.h"
// #include "../Movie/comedy.h"
// #include "../Movie/drama.h"
#include "../Movie/movie.h"
using namespace std;

class Blockbuster {
public:
  Blockbuster();
  ~Blockbuster();

  // Methods
  bool readMoviesFile(ifstream& file);
  bool readCustomersFile(ifstream& file);
  bool readCommandsFile(ifstream& file);
  void executeCommands();  // commandsDatabase queue for sequential execution
private:
  queue<Commands> commandsDatabase;             // Queue to run commands (Transaction Factory)
  list<pair<int, Customer>> customerDatabase; // Hash Table for store customers
  list<Movie> movieList;
  
// All containers: The BST for movies (or another container we can utilize),
  // and HashTable for Customers.
};
#endif