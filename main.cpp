// -----------------------------------main.h-----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/5/23
// ----------------------------------------------------------------------------
/* Purpose - Header file that reads from 3 text files and executes a series of
   commands that affect customers and movies.
*/
#include "Blockbuster/blockbuster.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  Blockbuster b;

  b.readMoviesFile();
  b.readCustomersFile();
  b.readCommandsFile();
  b.executeCommands();
}