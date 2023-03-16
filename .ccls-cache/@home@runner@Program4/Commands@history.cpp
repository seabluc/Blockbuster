// ------------------------------history.cpp-----------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
// Purpose - This file contains the implementations for the History 
// class, which is a derived class from Commands. The History class represents
// the command to display a customer's transaction history.
// ----------------------------------------------------------------------------
#include "history.h"

// ----------------------------Constructor-----------------------------------
// Constructs a History object with a given customerID.
// Preconditions: None.
// Postconditions: A History object is created with a specified customerID.
// ----------------------------------------------------------------------------
History::History(int customerID) {
  this->customerID = customerID;
  this->commandType = 'H';
}

// -----------------------------Destructor------------------------------------
// Destructor for the History object.
// Preconditions: A History object exists.
// Postconditions: The History object is destroyed.
// ----------------------------------------------------------------------------
History::~History() {}

// ------------------------------action---------------------------------------
// Executes the action method for the History object. Displays the command
// history for a customer if they exist in the CustomerHashTable.
// Preconditions: A valid CustomerHashTable is provided.
// Postconditions: If the customer exists, their command history is displayed.
// Returns true if successful, false if the customer does not exist.
// ----------------------------------------------------------------------------
bool History::action(CustomerHashTable &customerTable) {
  // Check if the customer exists
  if (customerTable.isExist(customerID)) {
    // Retrieve the customer from the customerTable
    Customer *customer = customerTable.retrieveCustomer(customerID);

    // Display the customer's command history
    cout << "History for " << customer->getCustomerID() << " "
         << customer->getCustomerFirstName() << " "
         << customer->getCustomerLastName() << ":" << endl;
    customer->displayCommandHistory();

    // Successfully executed the history action
    return true;
  } else {
    // The customer does not exist
    cout << "ERROR: Display History Failed -- Customer " +
                to_string(customerID) + " does not exist"
         << endl;
    return false;
  }
}