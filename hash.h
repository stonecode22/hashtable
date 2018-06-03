#ifndef HASH_H
#define HASH_H

#include"list.h"

class hashTable
{
 public:
  hashTable();
  ~hashTable();
  int add(student kid);
  void display();
  
 private:
  int hf(int key);
  list* array;
  int size;
};
  

#endif
