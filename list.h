#ifndef LIST_H
#define LIST_H

#include"student.h"

struct node
{
  student kid;
  node* next;
};

class list
{
 public:
  list();
  ~list();
  int add(student newKid);
  int rem(int id);
  int colCheck();
  void display();
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
