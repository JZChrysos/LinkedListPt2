#include "Node.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
//prototypes
void add(Node * current, Node * newnode, Studentr * newstudent);
void print(Node *);
void del(Node *, int);
void average();
//create initial student
Studentr * headstudptr = new Studentr();
//create Node head
Node * head = new Node(headstudptr);
//I have head attached to a blank student, and all functions are designed to skip over it.
//main
int main(){	
	// enter loop
	bool quit = false;
	while(quit == false){
		cout << "Add (A), Print (P), Delete (D), aVerage (V), or Quit (Q)?" << endl;
		char response;
		cin >> response;
		if (response == 'A'){
		// create new student 'newstudent' and cin info
		Studentr * newstudent = new Studentr();
		cout << "first: ";
		cin >> newstudent->first;
		cout << endl << "last: ";
		cin >> newstudent->last;
		cout << endl << "ID: ";
		cin >> newstudent->ID;
		cout << endl << "GPA: ";
		cin >> newstudent->GPA;
		// create new Node with student newstudent
		Node * newnode = new Node(newstudent);
		add(head, newnode, newstudent);
		}
		else if (response == 'P'){
		print(head->getNext());	
		}
		else if (response == 'D'){
		cout << "What student ID would you like to delete?" << endl;
		int delID;
		cin >> delID;
		del(head, delID);
		}
		else if (response == 'V'){
		average();
		}
		else if (response == 'Q'){
		quit = true;
		}
		else cout << "You should respond either A, P, D, V, or Q!" << endl;		
	};
	return 0;
};
// add
void add(Node * current, Node * newnode, Studentr * newstudent){
	//checks if the next student ID is greater, then inserts. If this never happens, puts last.
	if(current->getNext() != NULL){
		if(current->getNext()->getStudent()->ID > newstudent->ID){
			newnode->setNext(current->getNext());
			current->setNext(newnode);
		}
		else add(current->getNext(), newnode, newstudent);
	}
	else{
		current->setNext(newnode);
		newnode->setNext(NULL);
	};
};
// print
void print(Node * current){	
	// goes until the next node is null, prints the info of each student
	if(current != NULL){
		cout << current->getStudent()->first << " " << current->getStudent()->last << ", " << current->getStudent()->ID << ", " << setprecision(3) << current->getStudent()->GPA << endl;
		print(current->getNext()); // recursion
	};	
};
// delete
void del(Node * current, int delID){
	// checks if the next student is called to delete, if it is then points current to the next next node  
	if(current->getNext() != NULL){
		if(current->getNext()->getStudent()->ID == delID){
			Node * temp = current->getNext();
			current->setNext(current->getNext()->getNext());
			delete temp; // destructor should take care of memory leaks!
		}
		else del(current->getNext(), delID);
	}
	else cout << "ID not found! Sorry :(" << endl;
};
// average
void average(){
	double x = 0;
	int n = 0;
	Node * current;
	current = head->getNext();
	// x is the cumulative GPA, n is the number of students
	while(current != NULL){
		x += current->getStudent()->GPA;
		n++;
		current = current->getNext();
	};
	cout << "The average GPA is " << setprecision(3) << x / n << endl;
};
