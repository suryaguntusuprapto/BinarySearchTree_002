#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild; 

	//contructor for node class
	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;

	BinaryTree() {
		ROOT = NULL; //Initializing ROOT TO NULL
	}

	void insert(string element) {  //insertna node in the binary search tree
		Node* newNode = new Node(element, NULL, NULL); //Allocate memory for the new node
		newNode->info = element; //Assign value to the data field of the new node
		newNode->leftchild = NULL; //Make the left child of the new node point to NULL
		newNode->rightchild = NULL;  //Make the right child of the new node point to NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); //locate the node which will be the parent of the node to be inserted

		if (parent == NULL) // If the parent is NULL (tree is empty)
		{
			ROOT = newNode; //Mark the new node as ROOT
			return; //EXIT
		}

		if (element < parent->info) //if the value in the data field of the new node is greater than that of the parent
		{
			parent->leftchild = newNode; //make the left child of the parent point to the new node
		}
		else if (element > parent->info) //if the value in the data field of the new node is greater than that of the parent
		{
			parent->rightchild = newNode; //make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode) {
		//this function searches the currentNode of the specified Node as well as the current Node of its parent

		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}
};