/*
    WAP to implement Queue using SLL
    Submitted By:
        Name: Anjali Bansal
        Roll No: 04
*/

#include<iostream>
#include<conio.h>
#include<cstring>
#include<cstdlib>

using namespace std;

template <class T> class SLinkedList;
template <class T>
class SNode {
    /*
    objective: Create a class for a Node for Single Linked list
    input parameters: none
    output value: none
    description: SNode class defines the node structure
    approach: Class defines data item is names element with datatype string
            and link is named next pf snode type
    */
    private:
      T element;
      SNode* next;
    friend class SLinkedList<T>; // provides SLinkedList access to SNode
};


template <class T>
class SLinkedList {
    /*
    objective: Create a Single Linked List class
    input parameters: none
    output value: none
    side effects: Class SlinkedList defines Single Linked LIst class
    approach: Class definition
    */
    public:
    SLinkedList();                           // empty list constructor
    ~SLinkedList();                          // destructor
    bool empty();                            // is list empty?
    T front();                               // get front element
    void addBack(T e);                       // add to back of list
    void removeFront();                      // remove from front
    void print();                            // prints the SLL
    private:
    SNode<T>* head;                          // pointer to the head of list
};


template <class T>
SLinkedList<T>::SLinkedList() {
    head = NULL;
}


template <class T>
SLinkedList<T>::~SLinkedList() {
    delete head;
}


template <class T>
bool SLinkedList<T>::empty() {
    if(head == NULL) {
        return true;
    }
    else {
        return false;
    }
}


template <class T>
T SLinkedList<T>::front() {
    return head->element;
}


template <class T>
void SLinkedList<T>::addBack(T e) {
    SNode<T> *newnode = new SNode<T>();
    newnode->element = e;
    newnode->next = NULL;

    if(head == NULL){
		head = newnode;
		return;
	}

    SNode<T> *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}


template <class T>
void SLinkedList<T>::removeFront() {
    if(head == NULL) {
        cout << "\n Queue is empty!!";
    }
    else {
        SNode<T> *newnode = head;
        head = head->next;
        delete newnode;
    }
}


template <class T>
void SLinkedList<T>::print() {
    if(head == NULL) {
        cout << "\n Queue is empty!!";
    }
    else {
        cout << "\n Queue is: ";
        SNode<T> *temp = head;
        while(temp->next != NULL) {
            cout << temp->element << " -> ";
            temp = temp->next;
        }
        cout << temp->element;
    }
}


int main() {
    SLinkedList<int> sobj;
    char choice;
	char option;
	int element;

    do {
		cout << "\n *** MENU *** ";
		cout << "\n\n 1. Enqueue \n 2. Dequeue";
		cout << "\n 3. Display Queue \n 4. Exit";
		cout << "\n\n Enter option (1-4): ";
		cin >> option;

		switch(option) {
			case '1':
				cout << "\n Enter element: ";
                cin >> element;
                sobj.addBack(element);
                break;
			case '2':
				sobj.removeFront();
				break;
            case '3':
				sobj.print();
				break;
			case '4':
				exit(0);
				break;
			default:
				cout << "\n Oops..Invalid Choice!!";
		}

		cout << "\n\n Do you want to enter(y/n): ";
		cin >> choice;

	}while(choice == 'y' || choice == 'Y');
    return 0;
}
