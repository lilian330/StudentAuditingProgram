#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Student.h"

Student::Student(int i)
{
  id = i;
}

Student::~Student(){

}

void Student::operator+=(Course* c){
  // void Student::addCourse(Course* c){

  courseList += c;
  // courseList.add(c);
}

int  Student::getId(){
  return id;
}

float Student::computeGPA(){
  return courseList.computeGPA();

}
int Student::computeNumFW(){
  return courseList.computeNumFW();
}

void Student::print()
{
  cout<< endl << "Id: " << id << endl;
  cout<<"GPA: "<<computeGPA()<<endl;//print the student’s GPA.
  cout<<"numFW: "<<computeNumFW()<<endl;//print the student’s GPA.
  courseList.print();

}
