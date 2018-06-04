#include"list.h"

list::list()
{
  count = 0;
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
  count = 0;
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
      count++;
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
	  count--;
	  return 1;
	}
      else
	{
	  return rem(head->next, id);
	}
    }
}

int list::colCheck()
{
  return count;
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

int list::retId()
{
  if(head != NULL)
    {
      return head->kid.getId();
    }
  else
    {
      return -1;
    }
}

char* list::retFirst()
{
  if(head != NULL)
    {
      return head->kid.getFirst();
    }
  else
    {
      return NULL;
    }
}

char* list::retLast()
{
  if(head != NULL)
    {
      return head->kid.getLast();
    }
  else
    {
      return NULL;
    }
}

float list::retGpa()
{
  if(head != NULL)
    {
      return head->kid.getGpa();
    }
  else
    {
      return -1;
    }
}
      
