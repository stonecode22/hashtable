//Hash Table by Stone Yang
//A student list using hash tables & chaining
//Besides the randomly generated students, the user can ADD/DELETE more and display.
#include"hash.h"
#include<string.h>
#include<fstream>
#include<time.h>
#include<cstdlib>

student sGenerator(int id); //random student generator
const int SIZE = 30;

int main()
{
  hashTable ha;
  char command[8]; //command input
  int id = 0; //initialize the starting id to 0
  bool repeat = true; //used to repeat the program loop
  srand(time(NULL)); //random generator based on time

  //add initial 10 students into the list
  for(int i = 0; i < 10; i++)
    {
      id = i; //set the id to whatever this number is
      ha.add(sGenerator(i)); //add the random student to hash table
    }
  
  cout << "Hash Table in Student List:\n";

  while(repeat == true) //repeat loop
    {
      cout << "ADD a student, DELETE a student, or DISPLAY the list. QUIT to exit. (SIZE to check hash table size)\n";
      cin >> command; //prompts user for command
      cin.ignore();
      
      //make command all uppercase (non-case sensitive)
      for(int i = 0; i < strlen(command); i++)
	{
	  command[i] = toupper(command[i]);
	}

      //add command
      if(strcmp(command, "ADD") == 0)
	{
	  char first[SIZE];
	  char last[SIZE];
	  float gpa;

	  //Enter information
	  cout << "Enter first name: ";
	  cin.get(first, SIZE, '\n');
	  cin.ignore(SIZE, '\n');
	  cout << endl << "Enter last name: ";
	  cin.get(last, SIZE, '\n');
	  cin.ignore(SIZE, '\n');
	  cout << endl << "Enter GPA: ";
	  cin >> gpa;
	  id++; //increment the ID
	  student newStudent(first, last, gpa, id); //create a new student
	  ha.add(newStudent); //add the student into the hash table
	}
      //delete command
      else if(strcmp(command, "DELETE") == 0)
	{
	  int idSelection = 0;
	  
	  cout << "Enter ID of the student you want to delete: ";
	  cin >> idSelection; //prompts user to give an ID
	  ha.rem(idSelection); //deletes student with ID (without replacement)
	}
      //display command
      else if(strcmp(command, "DISPLAY") == 0)
	{
	  cout << "Student List:\n";
	  ha.display();
	}
      //end command
      else if(strcmp(command, "QUIT") == 0)
	{
	  cout << "Exiting program.\n";
	  repeat = false; //exits loop
	}
      //mostly for me, gives max size of hash table. Hopefully is useful to you as well!
      else if(strcmp(command, "SIZE") == 0)
	{
	  //default 100, if collisions exceed 3 in a given index, it will double
	  cout << ha.checkSize() << endl;
	}
      else
	{
	  cout << "Not a command, try again.\n";
	}	  
    }
  return 0;
}

//Generates a random student
student sGenerator(int id)
{
  int wordCount = 0; //counts # of names in the first.txt
  int lwordCount = 0; //counts # of names in the last.txt
  ifstream fileIn;
  fileIn.open("first.txt"); //open first.txt
  char firstNames[30]; //arrays for the names in first.txt
  char lastNames[30]; //arrays for the names in last.txt

  //first, check how many names are in the file
  if(fileIn) //if file exists
    {
      fileIn >> firstNames; //read in the 1st name
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn) //while not end of line and file still exists
    {
      wordCount++; //increment the word count
      fileIn >> firstNames; //read next names
      fileIn.ignore();
    }
  fileIn.clear();
  fileIn.seekg(0, ios::beg); //reset to beginning

  //now, add the words into the name holder 'fNameholder'
  char** fNameHolder; //holds the total names in first.txt
  fNameHolder = new char*[wordCount];
  wordCount = 0; //reset wordCount back to 0
  
  if(fileIn)
    {
      fileIn >> firstNames; //read in 1st name
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      fNameHolder[wordCount] = new char[strlen(firstNames)+1]; //create a new char array
      strcpy(fNameHolder[wordCount], firstNames); //copy the name from first.txt
      wordCount++; //increment wordCount
      fileIn >> firstNames; //read in others, loop again
      fileIn.ignore();
    }
  fileIn.close();
  fileIn.clear(); //clear it up

  //same thing, for last.txt
  fileIn.open("last.txt");
  //for lasts
    if(fileIn)
    {
      fileIn >> lastNames;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      lwordCount++;
      fileIn >> lastNames;
      fileIn.ignore();
    }
  fileIn.clear();
  fileIn.seekg(0, ios::beg);

  char** lNameHolder;
  lNameHolder = new char*[lwordCount];
  lwordCount = 0;
  
  if(fileIn)
    {
      fileIn >> lastNames;
      fileIn.ignore();
    }
  while(!fileIn.eof() && fileIn)
    {
      lNameHolder[lwordCount] = new char[strlen(lastNames)+1];
      strcpy(lNameHolder[lwordCount], lastNames);
      lwordCount++;
      fileIn >> lastNames;
      fileIn.ignore();
    }
  fileIn.close();
  fileIn.clear();

  //lastly, we pick at random indices
  int firstIndex = rand() % wordCount; //will pick a random index from fNameHolder and give a name
  int lastIndex = rand() % lwordCount; //will pick a random index from lNameHolder and give a name
  float randGpa = rand() / float(RAND_MAX / 4); //randomly picks a float between 0 and 4
  int givenId = id; //gives an id taken in (is incremented in main)
  
  student newStudent(fNameHolder[firstIndex], lNameHolder[lastIndex], randGpa, givenId); //finally, create the student
  return newStudent; //return student to insert into hash table
}
