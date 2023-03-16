// ------------------------------inventory.cpp---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// 
// Purpose - This file contains the implementations for the Inventory 
// class, which is a derived class from Commands. The Inventory class represents
// the command to display the current inventory of movies in the store.
// ----------------------------------------------------------------------------
#include "inventory.h"

// ----------------------------Constructor-----------------------------------
// Constructs an Inventory object.
// Preconditions: None.
// Postconditions: An Inventory object is created with the commandType 'I'.
// ----------------------------------------------------------------------------
Inventory::Inventory() { this->commandType = 'I'; }

// -----------------------------Destructor------------------------------------
// Destructor for the Inventory object.
// Preconditions: An Inventory object exists.
// Postconditions: The Inventory object is destroyed.
// ----------------------------------------------------------------------------
Inventory::~Inventory() {}

// ------------------------------action---------------------------------------
// Executes the action method for the Inventory object. Displays the list of
// movies in the inventory by genre (comedy, classics, drama).
// Preconditions: Valid lists of Movie pointers for comedyList, classicsList,
// and dramaList are provided.
// Postconditions: The list of movies in the inventory is displayed by genre.
// Returns true since the inventory action is always successful.
// ----------------------------------------------------------------------------
bool Inventory::action(list<Movie *> &comedyList, list<Movie *> &classicsList,
                       list<Movie *> &dramaList) {
  // Display the list of movies in the inventory by genre
  cout << "---------------------------" << endl;
  cout << "Comedy:" << endl;
  for (auto it = comedyList.begin(); it != comedyList.end(); ++it) {
    (*it)->displayMovie();
  }
  cout << endl;
  
  cout << "---------------------------" << endl;
  cout << "Classics:" << endl;
  for (auto it = classicsList.begin(); it != classicsList.end(); ++it) {
    (*it)->displayMovie();
  }
  cout << endl;
  
  cout << "---------------------------" << endl;
  cout << "Drama:" << endl;
  for (auto it = dramaList.begin(); it != dramaList.end(); ++it) {
    (*it)->displayMovie();
  }
  cout << endl;

  // Successfully executed the inventory action
  return true;
}