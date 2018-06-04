#include"student.h"

//constructor that initializes everything
student::student()
{
  first = NULL;
  last = NULL;
  gpa = 0;
  id = 0;
}

//destructor sets gpa and id to 0
student::~student()
{
  gpa = 0;
  id = 0;
}

//important constructor that creates a new student
student::student(const char* newFirst, const char* newLast, float newGpa, int newId)
{
  first = new char[strlen(newFirst)+1]; //make array for first name
  strcpy(first, newFirst); //copy into first
  last = new char[strlen(newLast)+1]; //same for last name
  strcpy(last, newLast);
  gpa = newGpa; //set gpa
  id = newId; //set id
}

//ALL OF BELOW FUNCTIONS ARE COVERED BY THE CONSTRUCTOR ABOVE
//These are used in case if you want to edit a student selection

//returns first name
char* student::getFirst()
{
  return first;
}

//sets first name
char* student::setFirst(const char* newFirst)
{
  first = new char[strlen(newFirst)+1]; //make array for first name
  strcpy(first, newFirst); //copy into first
  return first;
}

//returns last name
char* student::getLast()
{
  return last;
}

//sets last name
char* student::setLast(const char* newLast)
{
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  return last;
}

//returns gpa
float student::getGpa()
{
  return gpa;
}

//sets gpa
float student::setGpa(float newGpa)
{
  gpa = newGpa;
  return gpa;
}

//returns id
int student::getId()
{
  return id;
}

//sets id
int student::setId(int newId)
{
  id = newId;
  return id;
}

//displays name, gpa, and id
void student::displayAll()
{
  cout << endl << first << " " << last << endl;
  cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
  cout << "ID: " << id << endl;
}
  
