#include <iostream>
#include <iomanip>
using namespace std;

#include "CourseList.h"
CourseList::CourseList(){}
CourseList::~CourseList(){}


//fuction that returns the average of all course grades (between 0 and 12) for the student
// excluding the withdrawals
float CourseList::computeGPA(){
  Node *currNode = head;
  float gpa = 0.0f;
  int courseNum = 0;

  if(currNode == NULL){
    cout<<"Error: Empty List."<<endl;
    return gpa;
  }

  while (currNode != NULL) {
    int currGrade = currNode->data->getGrade();//the grade of current course;
    if(currGrade != -1){// excluding the withdrawals
      gpa += (float)currGrade;
      courseNum++;
    }
    currNode = currNode->next;
  }
  if(courseNum == 0){return 0;}
  return gpa/courseNum;

}
//returns the number of courses that
//the student has failed or from which the student has withdrawn
int CourseList::computeNumFW(){
  Node *currNode = head;
  int numFW = 0;
  if(currNode == NULL){
    cout<<"Error: Empty List."<<endl;
    return 0;
  }

  while (currNode != NULL) {
    int currGrade = currNode->data->getGrade();//the grade of current course;
    if((currGrade == -1 )||(currGrade == 0)){// excluding the withdrawals
      numFW++;
    }
    currNode = currNode->next;
  }
  return numFW;
}
