// Program to implement stack operations using STL queue

#include <iostream>
#include <cstdlib>
#include<queue>

using namespace std;

class Stack
{
	/*
	Objective: Create a class for implementing Stack using STL queue
	Input Parameters: None
	Return Value: None
	Description:  Class definition
	Approach: Class defines data member and member function of the stack class
	*/

	queue<int> q1;				   // to be considered as stack 
	queue<int> q2;				   // temporary queue
	
	public:
	Stack();				   // default constructor
	~Stack();				   // destructor to delete dynamically created array
	void push(int element);
	void pop();
	int peek();
	int size();				  // for current size of stack
	bool isEmpty();
	bool isFull();
};

Stack::Stack() {

	/*
    Objective: To allocate memory to stack object
    Input Parameters: None
    Return Value: None
    */

}

Stack::~Stack() {

	/*
    Objective: To de-allocate memory assigned to stack object
    Input Parameters: None
    Return Value: None
    */

}

bool Stack::isEmpty() {
	
	/*
    Objective: To check whether stack is empty or not
    Input Parameters: None
    Return Value: true if stack is empty else false
    */
    
    if(q1.empty())
        return true;
    else
        return false;
}

void Stack::push(int element) {

	/*
    Objective: To push an element at top of stack
    Input Parameters:
    	element: element to be inserted in stack
    Return Value: None
    Approach: Push element in stack using STL queues
    */
	
	int prevData;
	queue<int> temp;
	
	q2.push(element);
	while(!q1.empty()) {
		prevData = q1.front();
		q1.pop();
		q2.push(prevData);
	}
	
	temp = q1;
	q1 = q2;
	q2 = q1;
	
}

void Stack::pop() {

	/*
    Objective: To pop an element from top of stack
    Input Parameters: None
    Return Value:
    	element: element popped out from stack
    Approach: Pop element from stack if it is not empty else return -1
    */

	if(!isEmpty()) {
		q1.pop();
	}
	
}

int Stack::peek() {

	/*
    Objective: To return top element of stack
    Input Parameters: None
    Return Value:
    	element: element at top of stack if it is not empty else return -1
    */

	if(!isEmpty()) {
		return q1.front();
	}
	else
		return -1;
}

int Stack::size() {

	/*
    Objective: To check size of stack
    Input Parameters: None
    Return Value: size of stack
    */
    
	return q1.size();
}

int main() {

  /*
	Objective: To implement Stack using STL queue
	Input Parameters: None
	Return Value: 0
	Description:  Main function definition
	Approach: Using Class Stack
	*/
	
	Stack s;
	char choice;
	char option;
	int element;
	
	do {
		cout << "\n *** MENU *** ";
		cout << "\n\n 1. PUSH \n 2. POP \n 3. TOP ELEMENT \n 4. EXIT";
		cout << "\n\n Enter option (1-4): ";
		cin >> option;
		
		switch(option) {
			case '1':
				cout << "\n Enter element to push: ";
				cin >> element;
				s.push(element);
				break;
			case '2':
				if(s.isEmpty()) {
					cout << "\n Stack is empty!!";
				}
				else {
					cout << "\n Element poped is: " << s.peek();
					s.pop();
				}
				break;
			case '3':
				if(s.isEmpty()) {
					cout << "\n Stack is empty!!";
				}
				else {
					cout << "\n Element at top is: " << s.peek();
				}
				break;
			case '4':
				exit(0);
				break;
			default:
				cout << "Oops..Invalid Choice!!";
		}
		
		cout << "\n Do you want to enter(y/n): ";
		cin >> choice;
		
	}while(choice == 'y' || choice == 'Y');
	return 0;
}
