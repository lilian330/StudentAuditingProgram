#ifndef FWMONITOR_H
#define FWMONITOR_H

#include <string>
#include "Student.h"
#include "Monitor.h"
using namespace std;

class FWMonitor : public Monitor
{
public:
  FWMonitor(int i=0);
  ~FWMonitor();
  void update(Student*);       //checks if the given student’s number of FW courses is greater than the threshold;
private:
  int maxFW;                          //flagging a student’s number of FW courses
};

#endif
