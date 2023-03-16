// ----------------------------customerHashTable.h-----------------------------
// Group 9 CSS343D
// Created 3/01/23
// Date of Last Modification: 3/09/23
// ----------------------------------------------------------------------------
/* Purpose - Header file for a hash table that contain buckets to store 
   customers and perform the operations add, remove, and retrieve with near 
   O(1) efficiency. 
*/

#ifndef CUSTOMERHASHTABLE_H
#define CUSTOMERHASHTABLE_H
#include "customer.h"

// Hash table (chaining) to store all customers
static const int hashSize = 101; // Prime number to prevent collisions 

class CustomerHashTable {
public:
  CustomerHashTable();
  ~CustomerHashTable();

  // Methods
  bool isExist(int customerID);
  Customer* retrieveCustomer(int customerID);
  bool addCustomer(Customer &customer);
  bool removeCustomer(int customerID);
private:
  // Node to store into hash table (chaining), holds a Customer object
  struct HashNode {
    int customerID;    // CustomerID, which also serves as a key
    Customer customer; // The Customer object
    HashNode *next;
  };
  // Hash table to store all customers, represented as a double pointer
  HashNode **table;
  
  // Helper function
  int hashFunction(int key);
};
#endif