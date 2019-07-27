#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "Storage.h"

Storage::Storage()
{
  numStu = 0;
}
Storage::~Storage(){
  for(int i=0;i<numStu;++i){
    delete student[i];
  }
}

// void Storage::addStudent(Student *s)
void Storage::operator+=(Student *s)
{
  student[numStu] = s;
  numStu++;
}

void Storage::print()
{
  if(numStu > 0){
    cout << endl;
    cout << "Storage:" << endl;
    for(int i=0;i<numStu;++i)
    {
      student[i]->print();
    }
  }
}
