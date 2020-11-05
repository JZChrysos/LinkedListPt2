#pragma once
#include "Studentr.h"

class Node{

 public:
 Node* getNext();
  Studentr* getStudent();
  void setNext(Node*);
  Node(Studentr*);
  ~Node();
 private:
  Studentr* student;
  Node* next;
};
