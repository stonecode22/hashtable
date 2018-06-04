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
  int index = hf(kid.getId());
  if(array[index].colCheck() == 3)
    {
      list* listCopy;
      size = size*2;
      listCopy = new list[size];
      for(int i = 0; i < size/2; i++)
	{
	  int initId = array[i].retId();
	  while(initId != -1)
	    {
	      student newStudent(array[i].retFirst(), array[i].retLast(), array[i].retGpa(), array[i].retId());
	      listCopy[hf(initId)].add(newStudent);
	      array[i].rem(initId);
	      initId = array[i].retId();
	    }
	}
      int index = hf(kid.getId());
      delete[] array;
      array = listCopy;
      array[index].add(kid);
    }
  else
    {
      int index = hf(kid.getId());
      array[index].add(kid);
    }
  return 1;
}

int hashTable::rem(int id)
{
  if(array[hf(id)].rem(id) == 0)
    {
      cout << "No student with ID " << id << endl;
    }
  return 1;
}

void hashTable::display()
{
  for(int i = 0; i < size; i++)
    {
      array[i].display();
      if(array[i].retId() != -1)
	{
	  cout << "Index: " << i << endl;
	}
    }
}

int hashTable::hf(int key)
{
  return (3*key % size);
}

int hashTable::checkSize()
{
  return size;
}
