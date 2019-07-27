#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "GPAMonitor.h"
#include "Monitor.h"

GPAMonitor::GPAMonitor(int i)
 {
   minGPA = i;
 }
GPAMonitor::~GPAMonitor(){}
void GPAMonitor::update(Student *stu)
{
  if(stu->computeGPA() <  minGPA){
    string gpa = " id: " + to_string(stu->getId()) + "  GPA: " + to_string(stu->computeGPA());
    logs.push_back(gpa);
  }
}
