/*
    LINKEDLIST: Split a circular linked list into two equal parts circular linked lists. If the
    number of nodes in the list are odd then make first list with one extra node than second list.
    Submitted By:
        Name: Anjali Bansal
        Roll No: 04
*/

#include<iostream>
#include<conio.h>
#include<cstring>
#include<cstdlib>

using namespace std;

template <class T> class CircularList;
template <class T>
class CNode {
    /*
    objective: Create a class for a Node for Circular Linked list
    input parameters: none
    output value: none
    description: CNode class defines the node structure
    approach: Class definition
    */
    private:
      T element;
      CNode* next;
    friend class CircularList<T>; // provides CircularList access to CNode
};


template <class T>
class CircularList {
    /*
    objective: Create a Circular Linked List class
    input parameters: none
    output value: none
    side effects: Class CircularList defines Circular Linked List class
    approach: Class definition
    */
    public:
    CircularList();                          // empty list constructor
    ~CircularList();                         // destructor
    CNode<T>* newCNode(T element);           // Create node
    bool empty();                            // is list empty?
    T front();                               // get front element
    void addBack(T e);                       // add to back of list
    void removeElement(T e);                 // remove element from list
    void print();                            // prints the SLL
    void splitList(CircularList<T> list2);   // split the lists into two halves
    private:
    CNode<T>* head;                          // pointer to the head of list
};


template <class T>
CircularList<T>::CircularList() {
    head = NULL;
}


template <class T>
CircularList<T>::~CircularList() {
    delete head;
}


template<class T>
CNode<T>* CircularList<T>::newCNode(T e) {
    CNode<T>* temp = new CNode<T>();
    temp->element = e;
    temp->next = NULL;
    return temp;
}


template <class T>
bool CircularList<T>::empty() {
    if(head == NULL) {
        return true;
    }
    else {
        return false;
    }
}


template <class T>
T CircularList<T>::front() {
    return head->element;
}


template <class T>
void CircularList<T>::addBack(T e) {
    CNode<T> *newnode = newCNode(e);

    if(head == NULL){
		head = newnode;
		head->next = head;
		return;
	}

    CNode<T> *temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    temp = newnode;
    temp->next = head;
}


template <class T>
void CircularList<T>::removeElement(T e){
	CNode<T> *temp = head;
	if(temp == NULL){
		cout << "\n Linked list is empty!!";
	}
	else if(temp->element == e){
        if(temp->next == head) {
            head = NULL;
            delete temp;
        }
        else {
            while(temp->next != head){
                temp = temp->next;
            }
            CNode<T>* temp2 = head;
            head = temp2->next;
            temp->next = head;
            delete temp2;
        }
	}
	else {
        while(temp->next != head && temp->next->element != e) {
            temp = temp->next;
        }
        if (temp->next != head){
            CNode<T> *temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next = NULL;
            delete temp2;
        }
	}
}


template <class T>
void CircularList<T>::print() {
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
        CNode<T> *temp = head;
        while(temp->next != head) {
            cout << temp->element << " -> ";
            temp = temp->next;
        }
        cout << temp->element;
    }
}


template <class T>
void CircularList<T>::splitList(CircularList<T> list2) {
    /*
        Objective: To Split a circular linked list into two equal parts circular linked lists. If the
        number of nodes in the list are odd then make first list with one extra node than second list.
        Input parameters: second list list2
        Return Value: None
        Approach: Using Floyd cycle finding algorithm
    */
    if(head == NULL) {
        cout << "\n Linked list is empty, can't split!!";
    }
    else if(head->next == head){
        cout << "\n Linked list has single element!!";
	}
	else {
        CNode<T>* slow = head;
        CNode<T>* fast = head;

        while(fast->next != head && fast->next->next != head){
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow->next != head ){
            list2.addBack(slow->next->element);
            removeElement(slow->next->element);
        }
	}
	cout << "\n Lists after splitting is: ";
    cout << "\n\n List1: ";
	print();
	cout << "\n List2: ";
	list2.print();
}


int main() {
    /*
        Objective: To Split a circular linked list into two equal parts circular linked lists. If the
        number of nodes in the list are odd then make first list with one extra node than second list.
        Input parameters: None
        Return Value: 0
        Approach: Using splitList function
    */
    CircularList<int> list1, list2;
    char choice;
	char option;
	int element;

    do {
		cout << "\n *** MENU *** ";
		cout << "\n\n 1. Insert in List \n 2. Display Linked List";
		cout << "\n 3. Split List \n 4. Exit";
		cout << "\n\n Enter option (1-4): ";
		cin >> option;

		switch(option) {
			case '1':
				cout << "\n Enter element: ";
                cin >> element;
                list1.addBack(element);
                break;
			case '2':
				list1.print();
				break;
			case '3':
				list1.splitList(list2);
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
