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
