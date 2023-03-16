// ---------------------------------return.cpp---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/15/23
// ----------------------------------------------------------------------------
/* Purpose - Return class that executes the command of a customer returning a 
   specific movie. 
*/
#include "return.h"

// --------------------------------Constructor---------------------------------
// Constructs a Return object.
// Preconditions: customerID is a valid integer, and movie is a valid Movie
// pointer. 
// Postconditions: A Return object is created with the commandType 'R',
// and the customerID and movie pointer are initialized.
// ----------------------------------------------------------------------------
Return::Return(int customerID, Movie *movie) {
  this->customerID = customerID;
  this->movie = movie;
  this->commandType = 'R';
}

// ---------------------------------Destructor---------------------------------
// Destructor for the Return object.
// Preconditions: A Return object exists.
// Postconditions: The Return object is destroyed.
// ----------------------------------------------------------------------------
Return::~Return() {}

// -----------------------------------action-----------------------------------
// Executes the action method for the Return object. Increases the stock of
// the movie being returned, and updates the customer's history.
// Preconditions: A valid list of Movie pointers for movieList and a valid
// CustomerHashTable for customerTable are provided.
// Postconditions: The stock of the movie is increased, the customer's history
// is updated, and the customerTable is updated. Returns true if the return
// action is successfully executed, and false otherwise.
// ----------------------------------------------------------------------------
bool Return::action(list<Movie *> &movieList,
                    CustomerHashTable &customerTable) {
  if (customerTable.isExist(customerID)) {
    // Retrieve the customer from the customerTable
    Customer *customer = customerTable.retrieveCustomer(customerID);

    // Check if the movie exists in the list
    for (auto it = movieList.begin(); it != movieList.end(); ++it) {
      if (**it == *movie) {
        // Increase the stock of the movie
        (*it)->returnStock();

        // Add the action to the customer's history
        string action =
            "Returned " + (*it)->getTitle() + " by " + (*it)->getDirector();
        customer->addHistory(action);

        // Successfully executed the return action
        return true;
      }
    }
    // The movie is not available
    cout << "ERROR: Return Transaction Failed -- Movie does not Exist in the "
            "Inventory"
         << endl;
    return false;
  } else {
    cout << "ERROR: Return Transaction Failed -- Customer " +
                to_string(customerID) + " does not exist"
         << endl;
    return false;
  }
}