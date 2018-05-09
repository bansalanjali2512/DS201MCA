/*
    BINARYTREE: Given a binary tree, print out all its root to leaf paths.
    Submitted By:
        Name: Anjali Bansal
        Roll No: 04
*/

#include<iostream>
#include<conio.h>

using namespace std;

template<class T>
struct node {
    /*
        Objective: Create a template structure for a Node for Binary tree
        Input parameters: none
        Output value: none
        Description: node struct defines the structure of binary tree node
    */
    T data;
    node *left;
    node *right;
};

template<class T>
class BinaryTree {
    /*
        objective: Create a binary tree class
        input parameters: none
        output value: none
        side effects: Class BinaryTree defines binary tree class
        approach: Class definition
    */
    public:
    BinaryTree();
    void insertNode();
    void display();
    void inorder(node<T>* root);
    void findPaths(node<T>* root, int index);
    node<T> *newNode(T);
    node<T> *root;
    T *indexArr;
};


template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
    indexArr = new T[20];
}


template<class T>
node<T>* BinaryTree<T>::newNode(T element) {
    node<T>* temp = new node<T>;
    temp->data = element;
    temp-> left = NULL;
    temp->right = NULL;
    return temp;
}


template<class T>
void BinaryTree<T>::insertNode() {
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
}


template<class T>
void BinaryTree<T>::display() {
    inorder(root);
}


template<class T>
void BinaryTree<T>::inorder(node<T>* root) {
    if(root==NULL){
		return;
	}
	inorder(root->left);
	cout << root->data <<" ";
	inorder(root->right);
}


template<class T>
void BinaryTree<T>::findPaths(node<T>* root, int index) {
    /*
        Objective: Given a binary tree, print out all its root –to –leaf paths.
        Input parameters: root and index
        Return Value: 0
        Approach: Using array to store index
    */
    if(root == NULL) {
		return;
	}
	indexArr[index] = root->data;
	index++;
	if(root->left == NULL && root->right ==  NULL ) {
		for(int i = 0; i < index-1; i++){
			cout << indexArr[i] <<" -> ";
		}
		cout << indexArr[index-1];
		cout << "\n";
		return;
	}
	else {
		findPaths(root->left, index);
		findPaths(root->right, index);
	}
}


int main() {
    /*
        Objective: Given a binary tree, print out all its root –to –leaf paths.
        Input parameters: None
        Return Value: 0
        Approach: Using eliminate function
    */
    BinaryTree<int> bobj;
    bobj.insertNode();
    cout << "\nInorder Traversal: ";
    bobj.display();
    cout << "\n\nPossible Paths: \n";
    bobj.findPaths(bobj.root, 0);
    return 0;
}
