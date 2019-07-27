#include <string>
#include "CourseList.h"

using namespace std;

template <class T>
class List
{
    public:
        List();//a constructor
        ~List();//a destructor to clean up the dynamically allocated memory
        void operator+=(T);//adds a new course to the list
        // void  add(T);//adds a new course to the list
        void  print();// prints the courses to the screen
    protected:
        class Node
         {
             friend class List;
             public:
               Node *next;//point to next list node
               T data;//point to Couese Node
         };
        Node *head;//the head of the list
        Node *tail;//the tail of the list
};

template <class T>
List<T>::List(){
    head = NULL;
    tail = NULL;
}

template <class T>
List<T>::~List(){
  Node *currNode = head;
  Node *temp;

  while (currNode != NULL ) {
    temp = currNode;
    currNode = currNode->next;
    head = currNode;
    delete temp->data;
    delete temp;

  }
}

// added the new course  in its correct position in the list,
//in ascending (increasing) order by course
template <class T>
void List<T>::operator+=(T c){
// void List<T>::add(T c){
  Node *newNode = new Node;
  newNode->data = c;
  newNode->next = NULL;

  if(head == NULL){//add in a new list
    head = newNode;
    tail = newNode;
    return;
  }

  Node *prevNode = NULL;
  Node *currNode = head;

  while(currNode != NULL){//loop to find the position to add newNode
    if(newNode->data->lessThan(currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if(currNode == head){//add newCorse before head
    newNode->next = head;
    head = newNode;
    return;
  }
  //add newCorse after prevNode currNode
  prevNode->next = newNode;
  newNode->next = currNode;

  if(currNode != NULL){//check if the newCorse add at last
    newNode->next = currNode;
  }else{
    tail = newNode;
  }
}

// ◦ after all data is printed,
//  indicate which course is at the head and which course is at the tail
template <class T>
void List<T>::print(){
  Node *currNode = head;

  if(currNode == NULL){
    cout<<"Error: Empty List."<<endl;
    return;
  }

  while (currNode != NULL) {
    currNode->data->print();

    currNode = currNode->next;
  }
  cout<<endl<<"Head:";
  head->data->print();
  cout<<"Tail:";
  tail->data->print();
  cout<<endl;
}
