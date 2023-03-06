// ---------------------------customerHashTable.cpp----------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/05/23
// ----------------------------------------------------------------------------
/* Purpose - Customer class of Blockbuster. Customers all have a unique 4-digit
   ID, last name, and a first name. Additionally, customers perform the
   commands of borrow and return for Movies and their commands history is 
   recorded.
*/
#include "customerHashTable.h"
#include "customer.h"

// ----------------------------Default Constructor-----------------------------
// Constructs an empty hash table with a size of 101.
// Precondition: None.
// Postcondition: Empty hash table that holds 101 buckets is created.
// ----------------------------------------------------------------------------
CustomerHashTable::CustomerHashTable() {
  for (int i = 0; i < hashSize; i++) {
    table[i] = new CustomerNode;
    table[i]->customer = nullptr;
    table[i]->next = nullptr;
  }
}

// ---------------------------------Destructor---------------------------------
// Deletes and deallocates the hash table.
// Precondition: None.
// Postcondition: Hash table is deleted and memory is deallocated.
// ----------------------------------------------------------------------------
CustomerHashTable::~CustomerHashTable() {
  // Will work on this after I've created customerHashTable
}

// ----------------------------------isEmpty-----------------------------------
// Checks to see if hash table is empty.
// Precondition: None.
// Postcondition: Returns true if hash table is empty, false if not.
// ----------------------------------------------------------------------------
bool CustomerHashTable::isEmpty() const {
  
}

// --------------------------------hashFunction--------------------------------
// Function that determines which bucket a customer will be stored into by  
// finding the modulus between a customer's 4-digit ID and size of the table.
// Precondition: None.
// Postcondition: Returns the modulus of a key (customerID) and hashSize.
// ----------------------------------------------------------------------------
int CustomerHashTable::hashFunction(int key) {
  return key % hashSize;
}

// ------------------------------retrieveCustomer------------------------------
// Retrieves and returns a customer by their ID.
// Precondition: None.
// Postcondition: Returns customer if found, or nullptr if not found.
// ----------------------------------------------------------------------------
Customer* CustomerHashTable::retrieveCustomer(int key) const {
  
}

// --------------------------------addCustomer---------------------------------
// Inserts a customer into hash table by using their ID and hashFunction(int).
// Precondition: None.
// Postcondition: Returns true if customer is added into hash table, false if
// customer could not be added.
// ----------------------------------------------------------------------------
bool CustomerHashTable::addCustomer(int key, Customer* customer) {
  
}

// -------------------------------removeCustomer-------------------------------
// Removes a customer from the hash table by using their ID and hashFunction.
// Precondition: None.
// Postcondition: Returns true if customer was removed, false if customer DNE.
// ----------------------------------------------------------------------------
bool CustomerHashTable::removeCustomer(int key) {
  
}
