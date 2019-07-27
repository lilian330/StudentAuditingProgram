#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include "Student.h"
using namespace std;

class Storage
{
    public:
      Storage();                      //a constructor
      ~Storage();                     //a destructor to clean up the dynamically allocated Student objects
      // void addStudent(Student *);     //adds a new student to the back of the array
      void operator+=(Student *);
      void print();                   //prints out all the student information to the screen
    private:
      Student *student[MAX_NUM_STU];  //a collection of students, represented as an array of Student pointers
      int numStu;                     //the number of students currently in storage
};

#endif
