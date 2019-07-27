#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"

Course::Course(int c, int t,string i,int g)
{
  code  = c;
  term  = t;
  instructor = i;
  grade = g;

}
bool Course::lessThan(Course* c){
  if(c->code == code){
    return (term < c->term);
  }
  return (code < c->code );
}

void Course::print()
{
  string str;
  cout << "-- COMP " << code << ":  ";
  cout << term<<"   ";
  cout << right << setw(2) << grade   << "  ";
  getGradeStr(str);
  cout << left << setw(3) << str << "   " ;
  cout << instructor<<endl;

}

void Course::getGradeStr(string& gradeStr)
{
  string gradeStrings[] = {
    "WDN", "F", "D-", "D", "D+", "C-", "C", "C+",
    "B-", "B", "B+", "A-", "A", "A+" };

  if ( grade >= -1 && grade <= 12 )
    gradeStr = gradeStrings[grade+1];
  else
    gradeStr = "Unknown";
}

int Course::getGrade()
{
  return grade;
}
