#include"hash.h"

hashTable::hashTable()
{
  size = 100;
  array = new list[size];
}

hashTable::~hashTable()
{
  delete[] array;
}

int hashTable::add(student kid)
{
  array[hf(kid.getId())].add(kid);
  return 1;
}

void hashTable::display()
{
  for(int i = 0; i < size; i++)
    {
      array[i].display();
    }
}

int hashTable::hf(int key)
{
  return (key % size);
}
