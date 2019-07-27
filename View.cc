#include <iostream>
#include <iomanip>

using namespace std;

#include "View.h"
#include "Storage.h"

void View::display(int& selection)// displaying the main menu and reading the user’s selection
{

    int numOptions = 1;
    selection = -1;

    cout << endl;
    cout << "(1) Add student" << endl;
    cout << "(0) Exit" << endl;

    while (selection < 0 || selection > numOptions) {
      cout << "Enter your selection: ";
      cin  >> selection;
    }

}


void View::readId(int& id)//reading the student id
{
  cout << "student id:   ";
  cin  >> id;

}
void View::readCourse(int &code, int &term,string & instructor,int &grade )// reading all the information from the user about one course
{
  cout << "course code <0 to end>:  ";
  cin  >> code;
  if (code != 0)
  {
    cout << "term:                    ";
    cin  >> term;
    cout << "instructor:              ";
    cin  >> instructor;
    cout << "grade:                   ";
    cin  >> grade;
  }

}
void View::print(Storage *s)
{
  cout << endl << endl << "STUDENT INFO: " << endl;
  s->print();

}
