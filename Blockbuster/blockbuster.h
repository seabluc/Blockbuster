// -------------------------------blockbuster.h--------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/09/23
// ----------------------------------------------------------------------------
/* Purpose - Header file that reads from 3 text files and executes a series of
   commands that affect customers and movies.
*/

#ifndef BLOCKBUSTER_H
#define BLOCKBUSTER_H
#include <fstream> // File reading
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <string>
// All Commands related files
#include "../Commands/borrow.h"
#include "../Commands/commands.h"
#include "../Commands/history.h"
#include "../Commands/inventory.h"
#include "../Commands/return.h"
// All Customer related files
#include "../Customer/customer.h"
#include "../Customer/customerHashTable.h"
// All Movie related files
#include "../Movie/classics.h"
#include "../Movie/comedy.h"
#include "../Movie/drama.h"
#include "../Movie/movie.h"

using namespace std;

class Blockbuster {
public:
  Blockbuster();
  ~Blockbuster();

  // Methods
  bool readMoviesFile();
  bool readCustomersFile();
  bool readCommandsFile();
  void executeCommands(); // utilize commandsQueue for sequential execution
private:
  queue<Commands *>
      commandsQueue; // Queue to run commands (Transaction Factory)
  // Linked lists for each movie genre
  list<Movie *> movieListComedy, movieListDrama, movieListClassics;
  CustomerHashTable customerTable; // Hash Table to store customers.
};
#endif