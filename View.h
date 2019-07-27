#ifndef VIEW_H
#define  VIEW_H
using namespace std;
#include <string>

#include "Storage.h"

class View{
  public:
    void display(int&);// displaying the main menu and reading the user’s selection
    void readId(int&);//reading the student id
    void readCourse(int&, int&, string&, int& );// reading all the information from the user about one course
    void print(Storage*);//printing out the storage
};

#endif
