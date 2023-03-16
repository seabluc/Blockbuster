// --------------------------------customer.cpp--------------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/09/23
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
  this->customerID = ID;
  this->customerLastName = lastName;
  this->customerFirstName = firstName;
}

// ------------------------------Copy Constructor------------------------------
// Copy construct that constructs a customer with an existing Customer.
// Precondition: None.
// Postcondition: Copy of a Customer is created.
// ----------------------------------------------------------------------------
Customer::Customer(const Customer &other) {
  this->customerID = other.customerID;
  this->customerLastName = other.customerLastName;
  this->customerFirstName = other.customerFirstName;
  this->customerHistory = other.customerHistory;
}

// ---------------------------------Destructor---------------------------------
// Deletes and deallocates customer nodes.
// Precondition: None.
// Postcondition: All nodes are deleted/deallocated.
// ----------------------------------------------------------------------------
Customer::~Customer() { deleteCustomerHistory(); }

// ---------------------------displayCommandHistory----------------------------
// Prints out a customer's full name along with their history of borrowing
// and returning movies.
// Precondition: None.
// Postcondition: Prints out customer's last name, first name, then their
// history of commands.
// ----------------------------------------------------------------------------
void Customer::displayCommandHistory() {
  for (int i = 0; i < getCustomerHistory().size(); i++) {
    cout << customerHistory[i] << endl;
  }
  cout << endl;
}

// ---------------------------------addHistory---------------------------------
// Pushes a string representation of a Command into a customer's history.
// Precondition: None.
// Postcondition: String representation of a command stored in vector.
// ----------------------------------------------------------------------------
void Customer::addHistory(const string &action) {
  customerHistory.push_back(action);
}

// ----------------------------getCustomerLastName-----------------------------
// Accessor method for customer's customerLastName.
// Precondition: None.
// Postcondition: Returns customer's customerLastName.
// ----------------------------------------------------------------------------
string Customer::getCustomerLastName() const { return customerLastName; }

// ----------------------------getCustomerFirstName----------------------------
// Accessor method for customer's customerFirstName.
// Precondition: None.
// Postcondition: Returns customer's customerFirstName.
// ----------------------------------------------------------------------------
string Customer::getCustomerFirstName() const { return customerFirstName; }

// -------------------------------getCustomerID--------------------------------
// Accessor method for customer's customerID.
// Precondition: None.
// Postcondition: Returns customer's customerID.
// ----------------------------------------------------------------------------
int Customer::getCustomerID() const { return customerID; }

/*
// -----------------------------getCustomerHistory-----------------------------
// Accessor method for customer's customerHistory.
// Precondition: None.
// Postcondition: Returns customer's customerHistory.
// ----------------------------------------------------------------------------
vector<Commands> Customer::getCustomerHistory() const {
  return customerHistory;
}
*/

// -----------------------------getCustomerHistory-----------------------------
// Accessor method for customer's customerHistory.
// Precondition: None.
// Postcondition: Returns customer's customerHistory.
// ----------------------------------------------------------------------------
vector<string> Customer::getCustomerHistory() const { return customerHistory; }

// ---------------------------deleteCustomerHistory----------------------------
// Deletes the history of commands for a customer.
// Precondition: None.
// Postcondition: Removes all values in customer's vector, customerHistory.
// ----------------------------------------------------------------------------
void Customer::deleteCustomerHistory() {
  if (!(this->customerHistory.empty())) {
    this->customerHistory.clear();
  }
}

// ---------------------------------operator=----------------------------------
// Assign an existing Customer object to another customer.
// Precondition: Customer must exist.
// Postcondition: Attributes of a Customer are assigned to another Customer.
// ----------------------------------------------------------------------------
Customer &Customer::operator=(const Customer &other) {
  if (this != &other) {
    this->customerID = other.customerID;
    this->customerLastName = other.customerLastName;
    this->customerFirstName = other.customerFirstName;
    this->customerHistory = other.customerHistory;
  }
  return *this;
}

// ---------------------------------operator==---------------------------------
// See if two customer objects are equivalent by their ID numbers.
// Precondition: The two customers must exist.
// Postcondition: Return true if IDs are equivalent, false if not.
// ----------------------------------------------------------------------------
bool Customer::operator==(const Customer &rhs) {
  if (this->getCustomerID() == rhs.getCustomerID()) {
    return true;
  } else {
    return false;
  }
}