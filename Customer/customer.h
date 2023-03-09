// ---------------------------------customer.h---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/05/23
// ----------------------------------------------------------------------------
// Purpose - Header file for all Blockbuster customers.

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>  // STL vector to store commands a customer has performed
#include "../Movie/movie.h" // Might not need this, we will see once we start implementing Movies
#include "../Commands/commands.h" // Might not need this, we will see once we start implementing Commands
using namespace std;

class Customer {
public:
  Customer();
  Customer(int customerID, string customerLastName, string customerFirstName);
  // ~Customer(); I think only customerHashTable has to worry about mem leaks. We do have a 
  // vector that Commands, but deleteCustomerHistory() method should deallocate accordingly... 
  // will test w/ memleaks soon

  //Methods
  void displayCommandHistory();

  /* What else should a customer be able to do?
  Customers can borrow and return movies, but that should be coming from our 
  Commands file.
  
When a Movie is borrowed or returned, the Movie's stock will change. 
  But I'm also certain that should be coming from the Commands file?

  */
  // Getters
  string getCustomerLastName() const;
  string getCustomerFirstName() const;
  int getCustomerID() const;
//  vector<Commands> getCustomerHistory() const;
  vector<string> getCustomerHistory() const;
  void deleteCustomerHistory();

  // Operator overload
  bool operator==(const Customer &rhs);
private:
  string customerLastName;
  string customerFirstName;
  int customerID;
  // Vector to track all customers and their history of transactions
  // Everytime borrow or return is executed from Commands, we will .push_back()
  // that command into the respective Customer's history

  // MIGHT CHANGE THIS TO <STRING>! We can probably just push_back a string
  // representation of a Command everytime a customer borrows or returns a movie..
  // We won't have to worry about this until we start implementing the Commands class tho
  // vector<Commands> customerHistory;
  vector<string> customerHistory; // keeping it like this this just for now to not see red squigglies lol
};
#endif