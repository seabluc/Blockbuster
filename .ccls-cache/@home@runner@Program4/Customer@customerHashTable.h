#ifndef CUSTOMERHASHTABLE_H
#define CUSTOMERHASHTABLE_H
#include "customer.h"

class CustomerHashTable {
public:
  CustomerHashTable();
  ~CustomerHashTable();

    // Methods
  bool isEmpty() const;
  int hashFunction(int key);
  Customer* retrieveCustomer(int key);
  void addCustomer(int key, Customer *customer);
  void removeCustomer(int key);
  Customer searchTable(int key);

private:
    // Hash table (chaining) to store all customers
    static const int hashSize = 101; // Large prime number
    // Array of linked list
    list<pair<int, Customer>> table[hashSize]; // List 1, Index 0, List 2, Index 1...

};
#endif