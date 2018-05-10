#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

template<class T>
struct node {
    T data;
    node *left;
    node *right;
};


template<class T>
class BST {
    public:
    node<T> *root;
    BST();
    node<T>* insertBST(node<T>* root, T e);
    node<T>* deleteBST(node<T>* root, T key);
    node<T>* minValue(node<T>* root);
    void display();
    void inorder(node<T>* root);
    void preorder(node<T>* root);
    void postorder(node<T>* root);
    bool searchBST(node<T>* root, T data);
    node<T> *newNode(T);
};


template<class T>
BST<T>::BST() {
    root = NULL;
}


template<class T>
node<T>* BST<T>::newNode(T element) {
    node<T>* temp = new node<T>;
    temp->data = element;
    temp-> left = NULL;
    temp->right = NULL;
    return temp;
}


template<class T>
node<T>* BST<T>::insertBST(node<T>* root, T e) {
    node<T>* temp = newNode(e);
    if(root == NULL) {
        root = temp;
        return root;
    }
    if(root->data > e) {
        root->left = insertBST(root->left, e);
	}
    else if(root->data < e){
        root->right = insertBST(root->right, e);
    }
    return root;
}


template<class T>
void BST<T>::display() {
    inorder(root);
}


template<class T>
void BST<T>::inorder(node<T>* root) {
    if(root==NULL){
		return;
	}
	inorder(root->left);
	cout << root->data <<" ";
	inorder(root->right);
}


template<class T>
void BST<T>::preorder(node<T>* root) {
    if(root==NULL){
		return;
	}
	cout << root->data <<" ";
	preorder(root->left);
	preorder(root->right);
}


template<class T>
void BST<T>::postorder(node<T>* root) {
    if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data <<" ";
}


template<class T>
bool BST<T>::searchBST(node<T>* root, T data) {
    if(root==NULL){
        return false;
	}
	else if(root->data > data) {
        return searchBST(root->left, data);
	}
    else if(root->data < data) {
        return searchBST(root->right, data);
    }
    else {
        return true;
    }
}


template<class T>
node<T>* BST<T>::minValue(node<T>* root) {
    node<T>* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}


template<class T>
node<T>* BST<T>::deleteBST(node<T>* root, T key)
{
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node<T>* temp = root->left;
            delete root;
            return temp;
        }

        node<T>* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}


int main() {
    BST<int> bobj;
    bobj.root = bobj.insertBST(bobj.root, 10);
    char choice;
	char option;
	int element;

    do {
		cout << "\n *** MENU *** ";
		cout << "\n\n 1. Insert \n 2. Delete";
		cout << "\n 3. Inorder \n 4. Preorder \n 5. Postorder \n 6. Search \n 7. Exit";
		cout << "\n\n Enter option (1-6): ";
		cin >> option;

		switch(option) {
			case '1':
				cout << "\n Enter element: ";
                cin >> element;
                bobj.insertBST(bobj.root, element);
                break;
			case '2':
			    cout << "\n Enter element: ";
                cin >> element;
				bobj.deleteBST(bobj.root,element);
				break;
            case '3':
				bobj.inorder(bobj.root);
				break;
            case '4':
				bobj.preorder(bobj.root);
				break;
            case '5':
				bobj.postorder(bobj.root);
				break;
			case '6':
			    cout << "\n Enter element to search: ";
                cin >> element;
				if(bobj.searchBST(bobj.root, element))
                    cout << "\n " << element << " found..!";
                else
                    cout << "\n " << element << " not found..!";
				break;
            case '7':
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
