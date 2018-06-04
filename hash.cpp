#include"hash.h"

//constructor initializing size, creating the hash table array of lists
hashTable::hashTable()
{
  size = 100;
  array = new list[size];
}

//deconstructor, deleting array
hashTable::~hashTable()
{
  delete[] array;
}

//add function
int hashTable::add(student kid)
{
  int index = hf(kid.getId()); //student index after going through hash function 
  if(array[index].colCheck() == 3) //if # of collisions in an index is already 3
    {
      list* listCopy; //new hash table pointer
      
      size = size*2; //double the size
      listCopy = new list[size]; //create the new hash table
      //loop to insert old information from original hash table into the new one
      for(int i = 0; i < size/2; i++)
	{
	  int initId = array[i].retId(); //ID of first student of an index in the array
	  while(initId != -1) //if there is a "head" node in a list, loop
	    {
	      //create a "new" student to replace the old student with same data
	      student newStudent(array[i].retFirst(), array[i].retLast(), array[i].retGpa(), array[i].retId());
	      listCopy[hf(initId)].add(newStudent); //put into the new list
	      array[i].rem(initId); //remove the old student from the old list
	      initId = array[i].retId(); //update initId and continue loop
	    }
	}
      int index = hf(kid.getId()); //update index
      delete[] array; //delete old array
      array = listCopy; //make array point to the new array
      array[index].add(kid); //finally, add the new kid (user-generated) into the new list
    }
  else //if collisions < 3, simply...
    {
      int index = hf(kid.getId()); //get index
      array[index].add(kid); //add it in
    }
  return 1;
}

//remove function
int hashTable::rem(int id)
{
  //removes a student based on student id 
  if(array[hf(id)].rem(id) == 0) //if the list in index hf(id) finds nothing
    {
      cout << "No student with ID " << id << endl; //send a not found message
    }
  return 1;
}

//display function
void hashTable::display()
{
  //for every index, print the list
  for(int i = 0; i < size; i++)
    {
      array[i].display();
      if(array[i].retId() != -1)
	{
	  cout << "Index: " << i << endl; //shows index; mostly for me
	}
    }
}

//incredibly secure hash function
int hashTable::hf(int key)
{
  return (3*key % size);
}

//returns the size of the hash table
int hashTable::checkSize()
{
  return size;
}
