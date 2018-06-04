#ifndef STUDENT_H
#define STUDENT_H

#include<string.h>
#include<iomanip> //for setprecision
#include<iostream>
using namespace std;

class student
{
 public:
  student(); //constructor that initializes everything in private
  ~student(); //destructor sets gpa and id to 0
  student(const char* first, const char* last, float gpa, int id); //constructor that takes in 4 arguments to create a student

  //self explanatory
  char* getFirst();
  char* setFirst(const char* newFirst);
  char* getLast();
  char* setLast(const char* newLast);
  float getGpa();
  float setGpa(float newGpa);
  int getId();
  int setId(int newId);
  void displayAll(); //displays information of the above
  
 private:
  char* first;
  char* last;
  float gpa;
  int id;
};

#endif
