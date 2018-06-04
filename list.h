#ifndef LIST_H
#define LIST_H

#include"student.h"

//linked list nodes, containing a student and a next node pointer(for chaining)
struct node
{
  student kid;
  node* next;
};

class list
{
 public:
  list(); //constructor that sets count to 0 and head to NULL
  ~list(); //destructor deletes the list
  int add(student newKid); //adds a node
  int rem(int id); //removes a node
  int colCheck(); //check if there is a collision (just returns count)
  void display(); //displays all student information in the list (not the entire hash)

  //functions below return info for hash table (used in hash.cpp)
  int retId();
  char* retFirst();
  char* retLast();
  float retGpa();
 private:
  node* head;
  int count;
  int add(node* &head, student newKid);
  int rem(node* &head, int id);
};

#endif
