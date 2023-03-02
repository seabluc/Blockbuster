#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <list>    // Hash Table
#include <cstring> // Key value pair in linked list (customerID, name)
#include <vector>   // STL vector to store commands a customer has performed
#include "../Movie/movie.h"
#include "../Commands/commands.h"
using namespace std;

class Customer {
public:
  Customer();
  Customer(int customerID, string customerLastName, string customerFirstName);
  virtual ~Customer();

  // Methods
  bool isEmpty() const;
  int hashFunction(int key);
  void addCustomer(int key, Customer customer);
  
  // Getters
  string getCustomerLastName() const;
  string getCustomerFirstName() const;
  int getCustomerID() const;

private:
  // Customer as nodes to store in hash table
  struct customerNode {
    Customer* customer;
    customerNode* next;
  };

  string customerLastName();
  string customerFirstName();
  int customerID;
  // Vector to track all customers and their history of transactions
  vector<Commands> history;
};
#endif