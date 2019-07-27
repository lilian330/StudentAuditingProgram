#ifndef CONTROL_H
#define CONTROL_H
using namespace std;
#include <string>
#include <vector>

#include "View.h"
#include "Storage.h"
#include "Monitor.h"
#include "StuServer.h"
#include "CourseList.h"

class Control{
  public:
    Control();
    ~Control();
    void launch();//implements the program control flow
    void notify(Student* newStu); //notify the monitor objects when a new student is created
  private:
    vector<Monitor*> monitors;//a data member to store a collection of Monitor object pointers
    Storage storage;//the Storage object that used to be declared in main()
    View view;//a new View object that will be responsible for user I/O
    StuServer stuServer;//a StuServer object as a data member of the Control class
};

#endif
