#ifndef COURSE_H
#define COURSE_H

class Course
{
  public:

    Course(int=0, int=0, string="",int=0);//constructor
    bool lessThan(Course*);// compares two courses
    void print();       //print the course information
    int getGrade();     //getter functions to return private grade

  private:
    int code;	          // course code, for example 2404 for COMP2404
    int grade;	        // numeric grade from 0 (F) to 12 (A+), with -1 for WDN
    int term;           // corse term, for example 201910 for winter 2019
    string instructor;  //the surname of instructor, for example "Laurendeau"
    void getGradeStr(string&);


};

#endif
