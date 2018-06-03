#include"list.h"

list::list()
{
  head = NULL;
}

list::~list()
{
  while(head != NULL)
    {
      node* temp = head->next;
      delete head;
      head = temp;
    }
}

int list::add(student newKid)
{
  return add(head, newKid);
}

int list::add(node* &head, student newKid)
{
  if(head == NULL)
    {
      node* newNode = new node;
      newNode->kid.setFirst(newKid.getFirst());
      newNode->kid.setLast(newKid.getLast());
      newNode->kid.setGpa(newKid.getGpa());
      newNode->kid.setId(newKid.getId());
      newNode->next = NULL;
      head = newNode;
      return 1;
    }
  else
    {
      return add(head->next, newKid);
    }
}

int list::rem(int id)
{
  return rem(head, id);
}

int list::rem(node* &head, int id)
{
  if(head == NULL)
    {
      return 0;
    }
  else
    {
      if(id == head->kid.getId())
	{
	  node* temp = head->next;
	  delete head;
	  head = temp;
	  return 1;
	}
      else
	{
	  return rem(head->next, id);
	}
    }
}

void list::display()
{
  if(head == NULL)
    {
      return;
    }
  else
    {
      node* temp = head;
      while(temp != NULL)
	{
	  temp->kid.displayAll();
	  temp = temp->next;
	}
    }
}
