/*
    WAP to implement Singly Linked List  ( class definition attached )
    Submitted By:
        Name: Anjali Bansal
        Roll No: 04
*/

#include<iostream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;

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
      string element;
      SNode* next;
    friend class SLinkedList; // provides SLinkedList access to SNode
};


class SLinkedList {
    /*
    objective: Create a Single LInked List class
    input parameters: none
    output value: none
    side effects: Class SlinkedList defines Single Linked LIst class
    approach: Class definition
    */
    public:
    SLinkedList();                            // empty list constructor
    ~SLinkedList();                            // destructor
    bool empty() const;                     // is list empty?
    const string& front() const;             // get front element
    void addFront(const string& e);         // add to front of list
    void addBack(const string& e);             // add to back of list
    void removeFront();                         // remove from front
    void removeEnd();                        // remove from end
    void print();                             // prints the SLL
    private:
    SNode* head;                             // pointer to the head of list
};


SLinkedList::SLinkedList() {
    head = NULL;
}

SLinkedList::~SLinkedList() {
    delete head;
}

bool SLinkedList::empty() const {
    if(head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

const string& SLinkedList::front() const {
    return head->element;
}

void SLinkedList::addFront(const string& e) {
    SNode *newnode = new SNode();
    newnode->element = e;
    newnode->next = head;
    head = newnode;
}

void SLinkedList::addBack(const string& e) {
    SNode *newnode = new SNode();
    newnode->element = e;
    newnode->next = NULL;

    if(head == NULL){
		head = newnode;
		return;
	}

    SNode *temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void SLinkedList::removeFront() {
    if(head == NULL) {
        cout << "\n Linked list is empty!!";
    }
    else {
        SNode *newnode = head;
        head = head->next;
        delete newnode;
    }
}

void SLinkedList::removeEnd() {
    if(head == NULL) {
        cout << "\n Linked list is empty!!";
    }
    else {
        SNode *temp = head;
        SNode *lastElement = NULL;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        lastElement = temp->next;
        temp->next = NULL;
        delete lastElement;
    }
}

void SLinkedList::print() {
    if(head == NULL) {
        cout << "\n Linked list is empty!!";
    }
    else {
        cout << "\n Linked list is: ";
        SNode *temp = head;
        while(temp->next != NULL) {
            cout << temp->element << " -> ";
            temp = temp->next;
        }
        cout << temp->element;
    }
}


int main() {
    SLinkedList sobj;
    char choice;
	char option;
	string element;

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
