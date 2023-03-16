// ---------------------------------customer.h---------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/09/23
// ----------------------------------------------------------------------------
// Purpose - Header file for all Blockbuster customers.

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>  // STL vector to store commands a customer has performed
#include "../Movie/movie.h" 
#include "../Commands/commands.h"
using namespace std;

class Customer {
public:
  // Constructors & Destructor
  Customer();
  Customer(int customerID, string customerLastName, string customerFirstName);
  Customer(const Customer& rhs);
  ~Customer(); 
  
  //Methods
  void displayCommandHistory();
  void addHistory(const string& action);

  // Getters
  string getCustomerLastName() const;
  string getCustomerFirstName() const;
  int getCustomerID() const;
  vector<string> getCustomerHistory() const;
  void deleteCustomerHistory();

  // Assignment operator
  Customer& operator=(const Customer& other);
  // Operator overload
  bool operator==(const Customer &rhs);
private:
  string customerLastName;
  string customerFirstName;
  int customerID;
  // Vector that holds their history of commands (borrow & return)
  vector<string> customerHistory; 
};
#endif