#ifndef HASH_H
#define HASH_H

#include"list.h"

class hashTable
{
 public:
  hashTable(); //constructor initializes size to 100, makes a new hash table
  ~hashTable(); //deconstructor that deletes hash table
  int add(student kid); //adds a kid into a list (also doubles size in a collision of 3)
  int rem(int id); //removes a student from a list
  void display(); //displays all linked lists of students in the hash table
  int checkSize(); //returns size of hash table
  
 private:
  int hf(int key); //hash function that locates an index based on ID
  list* array; //the hash table
  int size; //size of the hash table
};

#endif
