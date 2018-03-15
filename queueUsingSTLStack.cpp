// Program to implement queue operations using STL stack

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class Queue
{
	/*
	Objective: Create a class for implementing Queue using STL stack
	Input Parameters: None
	Return Value: None
	Description:  Class definition
	Approach: Class defines data member and member function of the Queue class
	*/

	stack<int> s1;				// to be considered as stack 
	stack<int> s2;				// temporary stack
	
	public:
	Queue();					// default constructor
	~Queue();					// destructor
	void push(int element);
	void pop();
	int front();
	int size();					// Current size of queue
	bool isEmpty();
};

Queue::Queue() {

	/*
    Objective: To allocate memory to queue object
    Input Parameters: None
    Return Value: None
    */

}

Queue::~Queue() {

	/*
    Objective: To de-allocate memory assigned to queue object
    Input Parameters: None
    Return Value: None
    */

}

bool Queue::isEmpty() {
	
	/*
    Objective: To check whether queue is empty or not
    Input Parameters: None
    Return Value: true if queue is empty else false
    */
    
    if(s1.empty())
        return true;
    else
        return false;

}

void Queue::push(int element) {

	/*
    Objective: To push an element at last in queue
    Input Parameters:
    	element: element to be inserted in queue
    Return Value: None
    Approach: Push element in queue
    */
	
	int prevData;
	stack<int> temp;
	
	s2.push(element);
	while(!s1.empty()) {
		prevData = s1.top();
		s1.pop();
		s2.push(prevData);
	}
	
	temp = s1;
	s1 = s2;
	s2 = s1;
	
}

void Queue::pop() {

	/*
    Objective: To pop an element from front of queue
    Input Parameters: None
    Return Value: None
    Approach: Pop element from queue if it is not empty
    */

	if(!isEmpty()) {
		s1.pop();
	}
	
}

int Queue::front() {

	/*
    Objective: To return element at front of queue
    Input Parameters: None
    Return Value:
    	element: element at front of queue if it is not empty else return -1
    */

	if(!isEmpty()) {
		return s1.top();
	}
	else
		return -1;
	
}

int Queue::size() {

	/*
    Objective: To check size of queue
    Input Parameters: None
    Return Value: size of queue
    */
    
	return s1.size();
}

int main() {
	
	Queue q;
	char choice;
	char option;
	int element;
	
	do {
		cout << "\n *** MENU *** ";
		cout << "\n\n 1. ENQUEUE \n 2. DEQUEUE \n 3. ELEMENT AT FRONT \n 4. EXIT";
		cout << "\n\n Enter option (1-4): ";
		cin >> option;
		
		switch(option) {
			case '1':
				cout << "\n Enter element to Enqueue: ";
				cin >> element;
				q.push(element);
				break;
			case '2':
				if(q.isEmpty()) {
					cout << "\n Queue is empty!!";
				}
				else {
					cout << "\n Element dequeued is: " << q.front();
					q.pop();
				}
				break;
			case '3':
				if(q.isEmpty()) {
					cout << "\n Queue is empty!!";
				}
				else {
					cout << "\n Element at top is: " << q.front();
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
