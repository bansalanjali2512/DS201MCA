#include<iostream>
#include<conio.h>

using namespace std;

template<class T>
struct node {
    T data;
    node *left;
    node *right;
};

template<class T>
class binarytree {
    node *root;
    public:
    binarytree();
    void insertNode(T element);
    void display();
    void inorder();
    node<T> *newNode(T);
};

template<class T>
binarytree<T>::binarytree() {
    root = NULL;
}

template<class T>
node* binarytree<T>::newNode(T element) {
    node* temp = new node<T>;
    temp->data = element;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

template<class T>
void binarytree<T>::insertNode(T element) {
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
}

template<class T>
void binarytree<T>::display() {

}

template<class T>
void binarytree<T>::inorder() {

}

int main() {

    return 0;
}
