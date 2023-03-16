// ------------------------------borrow.cpp------------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
//
// Purpose - This file implements the Borrow class. The Borrow class is
// responsible for handling the borrow command for a specific customer and
// movie. It updates the inventory of the movie and records the transaction in
// the customer's history.
//-----------------------------------------------------------------------------
#include "borrow.h"

// ----------------------------Constructor-----------------------------------
// Constructs a Borrow object with a customer ID and a Movie pointer.
// Preconditions: Valid customerID and movie pointer.
// Postconditions: A Borrow object is created with the given customerID and
// movie pointer.
// ----------------------------------------------------------------------------
Borrow::Borrow(int customerID, Movie *movie) {
  this->customerID = customerID;
  this->movie = movie;
  this->commandType = 'B';
}

// -----------------------------Destructor------------------------------------
// Destructor for the Borrow object.
// Preconditions: A Borrow object exists.
// Postconditions: The Borrow object is destroyed.
// ----------------------------------------------------------------------------
Borrow::~Borrow() {}

// ------------------------------action---------------------------------------
// Executes the borrow action, which attempts to borrow a movie for a customer.
// Preconditions: A list of movies and a customer hash table are provided.
// Postconditions: If the customer and movie exist and the movie has available
// stock, the stock is reduced, and the action is added to the customer's
// history. Returns true if the borrow action is successful, false otherwise.
// ----------------------------------------------------------------------------
bool Borrow::action(list<Movie *> &movieList,
                    CustomerHashTable &customerTable) {
  if (customerTable.isExist(customerID)) {
    // Retrieve the customer from the customerTable
    Customer *customer = customerTable.retrieveCustomer(customerID);

    // Check if the movie exists in the list and has available stock
    for (auto it = movieList.begin(); it != movieList.end(); ++it) {
      if (**it == *movie && (*it)->getStock() > 0) {
        // Reduce the stock of the movie
        (*it)->borrowStock();

        // Add the action to the customer's history
        string action =
            "Borrowed " + (*it)->getTitle() + " by " + (*it)->getDirector();
        customer->addHistory(action);

        // Successfully executed the borrow action
        return true;
      }
    }
    // The movie is not available
    cout << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the "
            "Inventory"
         << endl;
    return false;
  } else {
    cout << "ERROR: Borrow Transaction Failed -- Customer " +
                to_string(customerID) + " does not exist"
         << endl;
    return false;
  }
}