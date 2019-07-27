#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "View.h"
#include "Storage.h"
#include "Control.h"
#include "Monitor.h"
#include "GPAMonitor.h"
#include "FWMonitor.h"
#include "CourseList.h"


Control::Control()
{

  //dynamically creates a new GPAMonitor object with a minimum bound of 3.0,
  Monitor *newGPAM = new GPAMonitor(3.0);
  //dynamically creates a new FWMonitor object with a threshold of 2
  Monitor *newFwM = new FWMonitor(2);

  monitors.push_back(newGPAM);
  monitors.push_back(newFwM);
  //a STL vector of strings to hold the students that are retrieved from cloud storage
  vector<string> stuVect;
  stuServer.retrieve(stuVect);

  stringstream ss;
  int id, courseCode,term,grade;
  string instructor;


  for (int i=0; i < stuVect.size(); ++i) {
    ss.clear();
    ss.str(stuVect[i]);

    ss >> id;
    Student *newStu = new Student(id);
    while (1) {
      ss >> courseCode;
      if(courseCode == 0){
        break;
      }
      ss >> term >> grade >> instructor;
      Course *newCourse = new Course(courseCode,term,instructor,grade);
      (*newStu)+=newCourse;
      // newStu->addCourse(newCourse);
    }
    storage+=newStu;
    // storage.addStudent(newStu);
    notify(newStu);
    // cout << "Id:"<< id << ", Code: " << courseCode << ", term " << term<<",grade:"<<grade<<",In:" <<instructor<< endl;
  }

}
/*
• modify the Control destructor so that
it loops over every monitor object in its collection and calls the printLogs() function on it;
 the destructor should also deallocate the memory for the monitor objects
 */
Control::~Control()
{
  // cout << " ~Control "<<endl;
  for (int i = 0; i < monitors.size(); ++i){
    monitors[i]->printLogs();
    cout << endl ;
    delete monitors[i];
  }
}

void Control::launch()
{
  int     stuId, courseCode, grade, term;
  string  instructor;
  int     menuSelection;

  while (1) {
    view.display(menuSelection);

    if (menuSelection == 0)
      break;

    else if (menuSelection == 1) {

      view.readId(stuId);
      Student *student = new Student(stuId);//dynamically allocates a Student object

      while (1) {
        view.readCourse(courseCode, term, instructor,grade );//
        if (courseCode == 0)
          break;
        //dynamically allocates a new Course object with the user entered data
        Course *course = new Course(courseCode,term,instructor,grade);
        //adds the new course to the Student object using existing functions
        (*student)+=course;
        // student->addCourse(course);
      }
      //adds the student to storage using functions implemented in previous steps
      storage+=student;

      notify(student);
    }
  }
  //prints the content of the storage using a member function of that object
  storage.print();
}
void Control::notify(Student* newStu)
{
  for (int i=0; i< monitors.size(); ++i){
    monitors[i]->update(newStu);
  }

}
