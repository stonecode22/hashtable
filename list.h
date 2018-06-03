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
  void display();
 private:
  node* head;
  int add(node* &head, student newKid);
  int rem(node* &head, int id);
};

#endif
