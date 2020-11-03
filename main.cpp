#include "Node.h"
#include "Studentr.h"
#include <iostream>
#include <cstring>

using namespace std;
int main(){

  char name[20] = "";
  strcpy(name,"Jared");
  Studentr* jared = new Studentr(name);
  Node* head = new Node(jared);
  strcpy(name,"Rosa");
  Studentr* rosa = new Studentr(name);
  Node* next = new Node(rosa);
  head->setNext(next);
  Node* currentNode = head;
  while(true){

    cout << (currentNode->getStudent())->getName() << endl;
    if(currentNode->getNext()==NULL){

      break;

    }
    currentNode = currentNode->getNext();
    
  }
  return 0;
  
}
