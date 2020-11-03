#include "Studentr.h"
#include <cstring>

Studentr::Studentr(char* newname){

  name = new char[20];
  strcpy(name,newname);

}

char* Studentr::getName(){

  return name;

}

Studentr::~Studentr(){

  delete name;
  
}
