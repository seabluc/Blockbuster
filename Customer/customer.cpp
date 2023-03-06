// --------------------------------customer.cpp--------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/05/23
// ----------------------------------------------------------------------------
/* Purpose - Customer class of Blockbuster. Customers all have a unique 4-digit
   ID, last name, and a first name. Additionally, customers perform the
   commands of borrow and return for Movies and their commands history is
   recorded.
*/
#include "customer.h"

// ----------------------------Default Constructor-----------------------------
// Constructs an empty Customer.
// Precondition: None.
// Postcondition: Empty Customer object created.
// ----------------------------------------------------------------------------
Customer::Customer() {
  customerID = 0;
  customerLastName = "";
  customerFirstName = "";
}

// -------------------------Parameterized Constructor--------------------------
// Constructs an Customer with a unique 4-digit ID, last name, and first name.
// Precondition: None.
// Postcondition: Customer object with assigned data created.
// ----------------------------------------------------------------------------
Customer::Customer(int ID, string lastName, string firstName) {
  customerID = ID;
  customerLastName = lastName;
  customerFirstName = firstName;
}

// ---------------------------------Destructor---------------------------------
// Deletes and deallocates Customer nodes.
// Precondition: None.
// Postcondition: All nodes are deleted/deallocated.
// ----------------------------------------------------------------------------
Customer::~Customer() {
  // Will work on this after I've created customerHashTable
}

// ----------------------------getCustomerLastName-----------------------------
// Accessor method for Customer's customerLastName.
// Precondition: None.
// Postcondition: Returns Customer's customerLastName.
// ----------------------------------------------------------------------------
string Customer::getCustomerLastName() const {
  return customerLastName;
}

// ----------------------------getCustomerFirstName----------------------------
// Accessor method for Customer's customerFirstName.
// Precondition: None.
// Postcondition: Returns Customer's customerFirstName.
// ----------------------------------------------------------------------------
string Customer::getCustomerFirstName() const {
  return customerFirstName;
}

// -------------------------------getCustomerID--------------------------------
// Accessor method for Customer's customerID.
// Precondition: None.
// Postcondition: Returns Customer's customerID.
// ----------------------------------------------------------------------------
int Customer::getCustomerID() const {
  return customerID;
}

