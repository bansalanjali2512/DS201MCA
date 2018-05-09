/*
    LINKEDLIST: Reverse the linked list in pairs. For example a linked list 1-> 2-> 3 -> 4 -> 5,
    then after the function has been called the linked list must be 2-> 1->4 -> 3 -> 5.
    Submitted By:
        Name: Anjali Bansal
        Roll No: 04
*/

#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;


template <class T>
struct SNode {
    /*
    objective: Create a class for a Node for Single Linked list
    input parameters: none
    output value: none
    description: SNode class defines the node structure
    approach: Class defines data item is names element with datatype string
            and link is named next pf snode type
    */
    T element;
    SNode<T>* next;
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
    void addBack(T);                         // add to back of list
    void print();                            // prints the SLL
    void reverseListInPairs();               // reverse list in pairs
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
bool SLinkedList<T>::empty(){
    if(head == NULL) {
        return true;
    }
    else {
        return false;
    }
}


template <class T>
void SLinkedList<T>::addBack(T e) {
    SNode<T> *newnode = new SNode<T>;
    newnode->element = e;
    newnode->next = NULL;

    if(head == NULL){
		head = newnode;
		return;
	}

    SNode<T> *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}


template <class T>
void SLinkedList<T>::print() {
    /*
        Objective: To display list
        Input parameters: None
        Return Value: None
        Approach: Iterating using next pointer
    */
    if(head == NULL) {
        cout << "\n Linked list is empty!!";
    }
    else {
        cout << "\n Linked list is: ";
        SNode<T>* temp = head;
        while(temp->next != NULL) {
            cout << temp->element << " -> ";
            temp = temp->next;
        }
        cout << temp->element;
    }
}


template <class T>
void SLinkedList<T>::reverseListInPairs() {
    /*
        Objective: To Reverse the linked list in pairs.
        Input parameters: None
        Return Value: None
        Approach: Using two adjacent temp variables
    */
    SNode<T>* temp1 = head;
	SNode<T>* temp2 = head->next;
	SNode<T>* prev = NULL;
	while(temp2 != NULL){
		temp1->next = temp2->next;
		temp2->next = temp1;
		if(prev != NULL){
			prev->next = temp2;
		}
		if(head == temp1){
			head = temp2;
		}
		prev = temp1;
		if((temp1->next == NULL)||(temp1 == NULL)){
			break;
		}
		else{
			temp1 = temp1->next;
			temp2 = temp1->next;
		}
	}
}


int main() {
    /*
        Objective: To Reverse the linked list in pairs.
        Input parameters: None
        Return Value: 0
        Approach: Using reverseListInPairs function
    */

    SLinkedList<int> sobj;
    char choice;
	char option;
	int element;

    do {
		cout << "\n *** MENU *** ";
		cout << "\n\n 1. Insert \n 2. Display list \n 3. Reverse list in pairs \n 4.Exit";
		cout << "\n\n Enter option (1-4): ";
		cin >> option;

		switch(option) {
			case '1':
				cout << "\n Enter element: ";
                cin >> element;
                sobj.addBack(element);
                break;
			case '2':
				sobj.print();
				break;
            case '3':
                sobj.reverseListInPairs();
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
