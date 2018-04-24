/*
    WAP to implement templated Singly Linked List
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
    void addFront(T e);                      // add to front of list
    void addBack(T e);                       // add to back of list
    void removeFront();                      // remove from front
    void removeEnd();                        // remove from end
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
void SLinkedList<T>::addFront(T e) {
    SNode<T> *newnode = new SNode<T>();
    newnode->element = e;
    newnode->next = head;
    head = newnode;
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
        cout << "\n Linked list is empty!!";
    }
    else {
        SNode<T> *newnode = head;
        head = head->next;
        delete newnode;
    }
}

template <class T>
void SLinkedList<T>::removeEnd() {
    if(head == NULL) {
        cout << "\n Linked list is empty!!";
    }
    else if(head->next == NULL){
        SNode<T>* temp = head;
		head = NULL;
		delete temp;
	}
    else {
        SNode<T>* temp = head;
        SNode<T>* lastElement = NULL;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        lastElement = temp->next;
        temp->next = NULL;
        delete lastElement;
    }
}

template <class T>
void SLinkedList<T>::print() {
    if(head == NULL) {
        cout << "\n Linked list is empty!!";
    }
    else {
        cout << "\n Linked list is: ";
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
		cout << "\n\n 1. Insert at Front \n 2. Insert at End";
		cout << "\n 3. Delete from Front \n 4. Delete from End";
		cout << "\n 5. Display Linked List \n 6. Exit";
		cout << "\n\n Enter option (1-6): ";
		cin >> option;

		switch(option) {
			case '1':
				cout << "\n Enter element: ";
                cin >> element;
                sobj.addFront(element);
                break;
			case '2':
				cout << "\n Enter element: ";
                cin >> element;
                sobj.addBack(element);
                break;
			case '3':
				sobj.removeFront();
				break;
            case '4':
				sobj.removeEnd();
				break;
            case '5':
				sobj.print();
				break;
			case '6':
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
