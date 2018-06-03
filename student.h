#ifndef STUDENT_H
#define STUDENT_H

#include<string.h>
#include<iostream>
using namespace std;

class student
{
 public:
  student();
  ~student();
  student(const char* first, const char* last, float gpa, int id);
  char* getFirst();
  char* setFirst(const char* newFirst);
  char* getLast();
  char* setLast(const char* newLast);
  float getGpa();
  float setGpa(float newGpa);
  int getId();
  int setId(int newId);
  void displayAll();
  
 private:
  char* first;
  char* last;
  float gpa;
  int id;

};

#endif
