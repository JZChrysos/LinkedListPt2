#include "Node.h"
#include <iostream>

using namespace std;
Node::Node(Studentr* newstudent){
  next = NULL;
  student = newstudent;
}

Node* Node::getNext(){
  return next;
}

Studentr* Node::getStudent(){
  return student;
}

void Node::setNext(Node* newnext){
  next = newnext;
}

Node::~Node(){
  cout << "deleting node" << endl;
}


