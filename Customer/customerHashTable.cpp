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
  this->table = new HashNode *[hashSize];
  for (int i = 0; i < hashSize; i++) {
    table[i] = nullptr;
    table[i]->next = nullptr;
  }
}

// ---------------------------------Destructor---------------------------------
// Traverses the hash table to delete and deallocate all customers.
// Precondition: None.
// Postcondition: Buckets and hash table are deleted and memory is deallocated.
// ----------------------------------------------------------------------------
CustomerHashTable::~CustomerHashTable() {
  for (int i = 0; i < hashSize; i++) {
    HashNode *crawler = table[i];
    while (crawler != nullptr) {
      crawler->customer.deleteCustomerHistory();
      HashNode *rem = crawler;
      crawler = crawler->next;
      rem->next = nullptr;
      rem->customerID = 0;
      delete rem;
    }
  }
  delete[] table;
}

// ------------------------------retrieveCustomer------------------------------
// Retrieves and returns a customer by their ID.
// Precondition: None.
// Postcondition: Returns customer if found, or nullptr if not found.
// ----------------------------------------------------------------------------
Customer CustomerHashTable::retrieveCustomer(int customerID) {
  // Apply hashing to find the index for customer retrieval.
  int index = hashFunction(customerID);
  HashNode *found = table[index];
  while ((found != nullptr) && (found->customerID != customerID)) {
    found = found->next;
  }
  if (found->customerID == customerID) {
    return found->customer;
  } else {
    // Error message: Customer ID DNE within bucket.
    cerr << "ERROR: Customer w/ ID: " << customerID << " DNE." << endl;
  }
}

// --------------------------------addCustomer---------------------------------
// Inserts a customer into hash table by using their ID and hashFunction(int).
// Precondition: None.
// Postcondition: Returns true if customer is added into hash table, false if
// customer could not be added.
// ----------------------------------------------------------------------------
bool CustomerHashTable::addCustomer(Customer &customer) {
  // Return false if this customer already exists in the hash table.
  if (retrieveCustomer(customer.getCustomerID()) == customer) {
    return false;
  }
  // Apply hashing to find the index for hash table insertion.
  int index = hashFunction(customer.getCustomerID());
  // Assign ins pointer to customer arg, assign all members.
  HashNode *ins = new HashNode;
  ins->customerID = customer.getCustomerID();
  ins->customer = customer;
  // Place customer as the head of the bucket if index is occupied.
  if (table[index] != nullptr) {
    ins->next = table[index];
    table[index] = ins->next;
    return true;
  } else {
    // Index not occupied, place customer into directly into bucket.
    table[index] = ins;
    return true;
  }
}

// -------------------------------removeCustomer-------------------------------
// Removes a customer from the hash table by using their ID and hashFunction.
// Precondition: None.
// Postcondition: Returns true if customer was removed, false if customer DNE.
// ----------------------------------------------------------------------------
bool CustomerHashTable::removeCustomer(int customerID) {
  int index = hashFunction(customerID);
  HashNode *rem = table[index]; // Node to remove
  HashNode *prev = nullptr;     // Previous node to adjust next pointer
  // List traversal until customerID is found or list is empty.
  while ((rem != nullptr) && (rem->customerID != customerID)) {
    prev = rem;
    rem = rem->next;
  }
  // Value was not found
  if (rem == nullptr) {
    return false;
  }
  // If the while loop was not used then the value to remove is the first
  // element in the bucket.
  else if (prev == nullptr) {
    table[index] = rem->next;
  }
  // Node was found in the list, connect prev->next to rem->next to delete rem.
  else {
    prev->next = rem->next;
  }
  // Deallocate
  rem->customerID = 0; 
  rem->next = nullptr; // Do I need to do this or will the destructor handle it?
  delete rem;
}

// --------------------------------hashFunction--------------------------------
// Function that determines which bucket a customer will be stored into by
// finding the modulus between a customer's 4-digit ID and size of the table.
// Precondition: None.
// Postcondition: Returns the modulus of a key (customerID) and hashSize.
// ----------------------------------------------------------------------------
int CustomerHashTable::hashFunction(int customerID) {
  return customerID % hashSize;
}