#include"list.h"

//constructor initializes count and head
list::list()
{
  count = 0;
  head = NULL;
}

//destructor deletes everything in the list
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

//add functions
int list::add(student newKid)
{
  return add(head, newKid);
}

int list::add(node* &head, student newKid)
{
  if(head == NULL) //if at a NULL location
    {
      node* newNode = new node; //make a new node
      
      //set info to the info given by student 'newKid'
      newNode->kid.setFirst(newKid.getFirst());
      newNode->kid.setLast(newKid.getLast());
      newNode->kid.setGpa(newKid.getGpa());
      newNode->kid.setId(newKid.getId());
      newNode->next = NULL; //set next to NULL
      head = newNode; //head points to newNode
      count++; //increment count (used to detect collisions)
      return 1;
    }
  else //if not, keep traversing
    {
      return add(head->next, newKid);
    }
}

//remove functions
int list::rem(int id)
{
  return rem(head, id);
}

int list::rem(node* &head, int id)
{
  if(head == NULL) //if nothing's there or no ID matches
    {
      return 0; //don't do anything
    }
  else //otherwise
    {
      if(id == head->kid.getId()) //if the id given matches a student's id in the list
	{
	  node* temp = head->next; //set a temp to hold the next connections
	  delete head; //delete it
	  head = temp; //have head point to temp to reconnect the list
	  count--; //decrement count (used to detect collisions)
	  return 1;
	}
      else //if not, traverse
	{
	  return rem(head->next, id);
	}
    }
}

//checks for collision by returning the count of the list (used in hash.cpp)
int list::colCheck()
{
  return count;
}

//display function
void list::display()
{
  if(head == NULL) //if nothing there, do nothing
    {
      return;
    }
  else
    {
      node* temp = head;
      while(temp != NULL) //loop to display student information within the list
	{
	  temp->kid.displayAll();
	  temp = temp->next;
	}
    }
}

//functions below return info necessary for hash table functions
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
      
