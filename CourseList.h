#ifndef COURSELIST_H
#define COURSELIST_H

#include <string>
using namespace std;
#include "List.h"
#include "Course.h"

class CourseList:public List<Course*>
{
  public:
    CourseList();
    ~CourseList();
    float computeGPA();//returns the average of all course grades (between 0 and 12) for the student,excluding the withdrawals
    int   computeNumFW();//returns the number of failed or withdrawn courses

  private:
};
#endif
