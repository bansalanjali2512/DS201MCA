// Program to implement queue operations using template

#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

template<class T>
class Queue
{
    /*
	Objective: Create a class to implement Queue(circular) using dynamically created array
	Input Parameters: none
	Output Value: none
	Description:  Class definition
	Approach: Class definition provides data member and member functions for the Queue class
	*/

	T *arr;			// array to store queue elements
	int capacity;		// maximum capacity of the Q
	int front;			// front points to front element in the Q
	int rear;			// rear points to last element in the Q
	int count;			// current size of the Q

    public:
	Queue(int size = SIZE);			// constructor
	~Queue();
	void enqueue(T);
	void dequeue();
	T peek();  				// returns front element
	int size();				// returns current size of Q
	bool isEmpty();
	bool isFull();
};

template<class T>
Queue<T>::Queue(int size) {
    /*
	Objective: To construct object of class Queue
	Input Parameters:
        size: size of queue
	Output Value: none
	Description:  Constructor definition
	Approach:
	*/
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template<class T>
Queue<T>::~Queue() {
    /*
	Objective: To destruct object of class Queue
	Input Parameters: none
	Output Value: none
	Description:  Destructor definition
	Approach: Using delete
	*/
	capacity = 0;
    front = 0;
    rear = -1;
    count = 0;
    delete arr;
}

template<class T>
void Queue<T>::enqueue(T element) {
    if(!isFull()) {
        ++rear;
        arr[rear] = element;
        ++count;
    }
    else {
        cout << "\n Queue is Full!";
    }
}

template<class T>
void Queue<T>::dequeue() {
    if(!isEmpty()) {
        int element = arr[front];
        ++front;
        --count;
    }
}

template<class T>
T Queue<T>::peek() {
    if(!isEmpty()) {
        return arr[front];
    }
    else {
        return -1;
    }
}

template<class T>
int Queue<T>::size() {
    return count;
}

template<class T>
bool Queue<T>::isEmpty() {
    if(rear == -1)
        return true;
    else
        return false;
}

template<class T>
bool Queue<T>::isFull() {
    if(rear == capacity-1)
        return true;
    else
        return false;
}

int main() {
    Queue<int> q;
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
				if(q.isFull()) {
					cout << "\n Queue is empty!!";
				}
				else {
                    cout << "\n Enter element to Enqueue: ";
                    cin >> element;
                    q.enqueue(element);
				}
				break;
			case '2':
				if(q.isEmpty()) {
					cout << "\n Queue is empty!!";
				}
				else {
					cout << "\n Element dequeued is: " << q.peek();
					q.dequeue();
				}
				break;
			case '3':
				if(q.isEmpty()) {
					cout << "\n Queue is empty!!";
				}
				else {
					cout << "\n Element at top is: " << q.peek();
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
