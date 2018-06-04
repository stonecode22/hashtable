#include"student.h"

student::student()
{
  first = NULL;
  last = NULL;
  gpa = 0;
  id = 0;
}

student::~student()
{
  gpa = 0;
  id = 0;
}

student::student(const char* newFirst, const char* newLast, float newGpa, int newId)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  gpa = newGpa;
  id = newId;
}

char* student::getFirst()
{
  return first;
}

char* student::setFirst(const char* newFirst)
{
  first = new char[strlen(newFirst)+1];
  strcpy(first, newFirst);
  return first;
}

char* student::getLast()
{
  return last;
}

char* student::setLast(const char* newLast)
{
  last = new char[strlen(newLast)+1];
  strcpy(last, newLast);
  return last;
}

float student::getGpa()
{
  return gpa;
}

float student::setGpa(float newGpa)
{
  gpa = newGpa;
  return gpa;
}

int student::getId()
{
  return id;
}

int student::setId(int newId)
{
  id = newId;
  return id;
}

void student::displayAll()
{
  cout << endl << first << " " << last << endl;
  cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
  cout << "ID: " << id << endl;
}
  
