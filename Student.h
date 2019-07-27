#ifndef STUDENT_H
#define STUDENT_H

#include "defs.h"
#include "Course.h"
#include "CourseList.h"


class Student
{
  public:
    Student(int=0);
    ~Student();               //a destructor to clean up the dynamically allocated Course objects
    void  operator+=(Course*);
    // void  addCourse(Course*);  // adds a course to the back (the end) of the array
    float computeGPA();       //returns the average of all course grades (between 0 and 12) for the student,excluding the withdrawals
    int   computeNumFW();       //returns the number of failed or withdrawn courses
    int   getId();             //getter fuction to return private id of student
    void  print();

  private:
    int    id;
    CourseList courseList;
};

#endif
