#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#include "Monitor.h"
Monitor::~Monitor(){

}
void Monitor::printLogs(){
  cout << "Logs: "<<endl;
  for(int i = 0; i < logs.size(); i++) {
      // cout << i <<" ,  ";
      cout << logs[i] << endl;
  }
  cout<<endl;
    // cout << " Monitor print end  "<<endl;
}
