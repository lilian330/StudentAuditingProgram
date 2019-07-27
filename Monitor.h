#ifndef MONITOR_H
#define MONITOR_H

#include <string>
#include <vector>

#include "Student.h"
using namespace std;

class Monitor
{
public:

  virtual ~Monitor() = 0;
  virtual void update(Student*) = 0;// a pure virtual update() function
  void printLogs();             // member function that prints the collection of logs to the screen
protected:
  vector<string>logs;         //stores a collection of logs;
};

#endif
