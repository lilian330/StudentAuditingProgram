#ifndef GPAMONITOR_H
#define GPAMONITOR_H

#include <string>
#include "Student.h"
#include "Monitor.h"
using namespace std;

class GPAMonitor : public Monitor
{
public:
  GPAMonitor(int i=0);
  ~GPAMonitor();
  void update(Student*);//checks if the given student’s GPA is below the minimum threshold;
private:
  float minGPA;                      //represents the minimum threshold for GPAs to be flagged;
};

/*a data member that
represents the minimum threshold for GPAs to be flagged;
when the GPAMonitor object detects a student with a GPA below this minimum threshold, it will create a new log
• a constructor
• an implementation of the update(Student* stu) function that
checks if the given student’s GPA is below the minimum threshold;
 if it is, then the function will create a new log documenting the student id and the corresponding GPA, and it will add the new log to its collection*/

#endif
