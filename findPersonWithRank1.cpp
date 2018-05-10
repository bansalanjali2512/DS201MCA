/*
    LINKEDLIST: N people have decided to elect a leader by arranging themselves in a circle
    and eliminating every Mth person around the circle, closing the ranks as each person drops
    out. Find which person will be the last one remaining (with rank 1).
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
    void eliminate(int n, int m);            // eliminate every mth person around the circle
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
void CircularList<T>::eliminate(int n, int m) {
    /*
        Objective: To do: N people have decided to elect a leader by arranging themselves in a circle
        and eliminating every Mth person around the circle, closing the ranks as each person drops
        out. Find which person will be the last one remaining (with rank 1).
        Input parameters:
            n: no. of persons
            m: mth person to eliminate
        Return Value: None
        Approach: Iteratively deleting mth element till list contain only single element
    */
    if(head == NULL) {
        cout << "\n Linked list is empty!!";
    }
    else if(n == 1){
        cout << "\n Linked list has single element!!";
	}
	else {
        CNode<T>* temp = head;
        CNode<T>* temp2 = head->next;
        int rank = n;
        while(head->next != head){
            for(int i = 1; i < m-1; i++){
                temp = temp->next;
            }
            temp2 = temp->next;
            cout << "\n Person eliminated with rank " << rank << " is: " << temp2->element;
            temp = temp2->next;
            removeElement(temp2->element);
            rank--;
        }
        cout << "\n Person with rank 1 is: "<< head->element << endl;
	}
}


int main() {
    /*
        Objective: To do: N people have decided to elect a leader by arranging themselves in a circle
        and eliminating every Mth person around the circle, closing the ranks as each person drops
        out. Find which person will be the last one remaining (with rank 1).
        Input parameters: None
        Return Value: 0
        Approach: Using eliminate function
    */
    CircularList<int> cobj;
    int n, m;
    cout << "\n Enter n: ";
    cin >> n;
    cout << "\n Enter m: ";
    cin >> m;
    for(int i = 0; i < n; i++) {
        cobj.addBack(i+1);
    }
    cout << "\n Finding leader...\n";
    cobj.eliminate(n, m);
    return 0;
}
