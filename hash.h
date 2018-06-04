#ifndef HASH_H
#define HASH_H

#include"list.h"

class hashTable
{
 public:
  hashTable();
  ~hashTable();
  int add(student kid);
  int rem(int id);
  void display();
  int checkSize();
  
 private:
  int hf(int key);
  list* array;
  int size;
};
  

#endif
