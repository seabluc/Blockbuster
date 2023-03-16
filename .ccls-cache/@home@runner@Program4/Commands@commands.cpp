// ------------------------------commands.cpp----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// 
// Purpose - This file contains the implementations for the Commands
// class, which is a base class for all the commands that customers can perform
// on movies. Derived classes will handle specific command implementations.
// ----------------------------------------------------------------------------
#include "commands.h"

// ----------------------------Constructor-----------------------------------
// Constructs a base Commands object.
// Preconditions: None.
// Postconditions: A base Commands object is created.
// ----------------------------------------------------------------------------
Commands::Commands() {}

// -----------------------------Destructor------------------------------------
// Destructor for the base Commands object.
// Preconditions: A Commands object exists.
// Postconditions: The Commands object is destroyed.
// ----------------------------------------------------------------------------
Commands::~Commands() {}

// ------------------------------action---------------------------------------
// Executes the action method for the base Commands object. This method should
// not be called directly, and derived classes must implement their own action
// method.
// Preconditions: None.
// Postconditions: An error message is displayed, indicating that the base
// class action method should not be called directly. Returns false.
// ----------------------------------------------------------------------------
bool Commands::action() {
  // This is a base class method and should not be called directly.
  // Derived classes must implement their own action method.
  cerr << "ERROR: Base class 'Commands' action method should not be called "
          "directly."
       << endl;
  return false;
}