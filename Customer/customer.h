// ---------------------------------customer.h---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/05/23
// ----------------------------------------------------------------------------
// Purpose - Header file for all Blockbuster customers.

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <list>      // Hash Table
#include <cstring>   // Key value pair in linked list (customerID, name)
#include <vector>    // STL vector to store commands a customer has performed
#include "../Movie/movie.h"
#include "../Commands/commands.h"
using namespace std;

class Customer {
public:
  Customer();
  Customer(int customerID, string customerLastName, string customerFirstName);
  ~Customer();

  //Methods
  void displayCustomerName() const;
  void displayCommandHistory() const;
  
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

private:
  // Customer as nodes to store in hash table (chaining)
  struct CustomerNode {
    Customer* customer;
    CustomerNode* next;
  };
  string customerLastName;
  string customerFirstName;
  int customerID;
  // Vector to track all customers and their history of transactions
  // Everytime borrow or return is executed from Commands, we will .push_back()
  // that command into the respective Customer's history.
  vector<Commands> history;
};
#endif