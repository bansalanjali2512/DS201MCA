#include <iostream>
#include <cstdlib>
#define MAXSIZE 100  // or const int MAXSIZE=100;

using namespace std;


class Stack
{
	/*
	objective: Create a class for implementing Stack using array
	input parameters: none
	output value: none
	description:  class definition
	approach: Class defines data member and member function of the stack class
	*/
	int *arr;					// for dynamic array 
	int top;
	int capacity;				// checks size defined by user
	
	public:
	Stack();					// constructor to create array dynamically
	Stack(int size);
	~Stack();					// destructor to delete dynamically created array
	void push(int element);
	int pop();
	int peek();
	int size();					// Current size of stack
	bool isEmpty();
	bool isFull();
};

Stack::Stack() {
	arr = new int[MAXSIZE];
	top = -1;
	capacity = MAXSIZE;
}

Stack::Stack(int size) {
	arr = new int[size];
	top = -1;
	capacity = size;
}

Stack::~Stack() {
	delete []arr;
	capacity = 0;
	top = -1;
}// Program to implement using stack operations

#include <iostream>
#include <cstdlib>
#define MAXSIZE 100  			// or const int MAXSIZE=100;

using namespace std;


class Stack
{
	/*
	Objective: Create a class for implementing Stack using array
	Input Parameters: None
	Return Value: None
	Description:  Class definition
	Approach: Class defines data member and member function of the stack class
	*/

	int *arr;					// for dynamic array 
	int top;					// to access top element
	int capacity;				// checks size defined by user
	
	public:
	Stack();					// default constructor
	Stack(int size);			// constructor to create array dynamically using user defined size
	~Stack();					// destructor to delete dynamically created array
	void push(int element);
	int pop();
	int peek();
	int size();					// Current size of stack
	bool isEmpty();
	bool isFull();
};

Stack::Stack() {

	/*
    Objective: To allocate memory to stack object
    Input Parameters: None
    Return Value: None
    */

	arr = new int[MAXSIZE];
	top = -1;
	capacity = MAXSIZE;
}

Stack::Stack(int size) {

	/*
    Objective: To allocate memory to stack object
    Input Parameters:
    	size: size of stack
    Return Value: None
    */

	arr = new int[size];
	top = -1;
	capacity = size;
}

Stack::~Stack() {

	/*
    Objective: To de-allocate memory assigned to stack object
    Input Parameters: None
    Return Value: None
    */

	delete []arr;
	capacity = 0;
	top = -1;
}

bool Stack::isEmpty() {
	
	/*
    Objective: To check whether stack is empty or not
    Input Parameters: None
    Return Value: true if stack is empty else false
    */

	if(top == -1)
		return true;
	else
		return false;
}

bool Stack::isFull() {

	/*
    Objective: To check whether stack is full or not
    Input Parameters: None
    Return Value: true if stack is full else false
    */

	if(top == capacity-1)
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
    Approach: Push element in stack if it is not full else print stack overflow
    */

	if(isFull()) {
		cout << "\n Oops! Stack Overflow !!";
	}
	else {
		top++;
		arr[top] = element;
	}
}

int Stack::pop() {

	/*
    Objective: To pop an element from top of stack
    Input Parameters: None
    Return Value:
    	element: element popped out from stack
    Approach: Pop element from stack if it is not empty else return -1
    */

	if(!isEmpty()) {
		int popElement = arr[top];
		top--;
		return popElement;
	}
	else
		return -1;
}

int Stack::peek() {

	/*
    Objective: To return top element of stack
    Input Parameters: None
    Return Value:
    	element: element at top of stack if it is not empty else return -1
    */

	if(!isEmpty()) {
		return arr[top];
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

	return top+1;
}


bool Stack::isEmpty() {
	if(top == -1)
		return true;
	else
		return false;
}

bool Stack::isFull() {
	if(top == capacity-1)
		return true;
	else
		return false;
}

void Stack::push(int element) {
	if(isFull()) {
		cout << "Stack Overflow";
	}
	else {
		top++;
		arr[top] = element;
	}
}

int Stack::pop() {
	if(!isEmpty()) {
		int poped = arr[top];
		top--;
		return poped;
	}
	else
		return -1;
}

int Stack::peek() {
	if(!isEmpty()) {
		return arr[top];
	}
	else
		return -1;
}

int Stack::size() {
	return top+1;
}
