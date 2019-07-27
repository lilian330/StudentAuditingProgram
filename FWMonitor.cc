#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "FWMonitor.h"
#include "Monitor.h"

/*
an implementation of the update(Student* stu) function that
 if the given student’s number of FW courses is greater than the threshold,
 then the function will create a new log documenting the student id and the corresponding number of FW courses,
 and it will add the new log to its collection
 */
 FWMonitor::FWMonitor(int i)
 {
   maxFW = i;
 }
 FWMonitor::~FWMonitor(){ }
void FWMonitor::update(Student *stu)
{
  if(stu->computeNumFW() > maxFW){
    string fw = " id: " + to_string(stu->getId())+"  FW: "+ to_string(stu->computeNumFW());
    logs.push_back(fw);
  }

}
