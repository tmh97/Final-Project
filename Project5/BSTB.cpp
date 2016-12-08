/*
 * BTSB.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: thomashuber
 */



#include "BSTB.hpp"

#include <iostream>
#include "NodeTB.hpp"

// constructor, creates new BST
//inital root is set to null, count is set to 0

BSTB::BSTB(){
	root = NULL;
	count = 0;
}

BSTB::~BSTB(){
	if(root==NULL){
		cout << "The tree is empty" << endl;
		return;
	}

	else{
		deleteTree(root);
	}
}

//assists destructor in deleting the Tree
// deletes the specified tree with tmp == root

void BSTB::deleteTree(NodeTB *tmp){
	if(tmp==NULL){
		return;
	}
	deleteTree(tmp->left); // recursively calls the left children of the root
	deleteTree(tmp->right);//recursively calls the right children of the root
	delete tmp;
}

//insert(string x)
//this function takes in a string x and returns nothing
//it inserts x into the tree
bool BSTB::insert(string x){
	NodeTB *node = new NodeTB(x);
	if(count == 0){
		root = node;
		count++;
		return true;
	} //if statement making the new node the root of the tree if the count = 0
	else{
		bool leftorright = true;
		NodeTB *tmp = root;
		NodeTB *tmp2 = root;
		while(tmp != NULL){
			tmp2 = tmp;
			if(node->data < tmp->data){
				tmp = tmp->left;
				leftorright = true;
			} //if statement moving to tmps left child if the nodes data is less than tmps data
			else if(node->data > tmp->data){
				tmp = tmp->right;
				leftorright = false;
			}//if statement moving to tmps right child if the nodes data is greater than tmps data
			else{
				return false;
			}
			tmp = node;
			count++;
		}//while loop iterating through as long as tmp is not NULL
		node->parent = tmp2;
		if(leftorright == true){
			tmp2->left = node;
		}//if statement making tmp2s left child tmp if tmp is less than tmp2
		else{
			tmp2->right = node;
		}//if statement making tmp2s right child tmp if tmp is greater than tmp2
	}
	adjustBalances(node);
	return true;
}

//printTreeio()
//this function takes nothing and returns nothing
//it prints out the data in the tree in order
void BSTB::printTreeio(){
	cout << "Print out in order: " << endl;
	if(root==NULL){
		cout << "This tree is empty" << endl;
		return;
	} //if statement specifying what to do when the tree is empty
	else{
		printTreeio(root);
		cout << endl;
	}//else statement calling printTreeio(root) when the tree is not empty
}

//printTreeio(NodeTB *n)
//this function takes a pointer to a NodeTB (n) and returns nothing
//it recursively prints out the data in the tree in order starting at root n
void BSTB::printTreeio(NodeTB *n){
	if(n != NULL){
		printTreeio(n->left);
		cout<<n->data<<endl;
		printTreeio(n->right);
	}//if statement traversing the tree in order when the root plugged in is not NULL
}

//printTreePre()
//this function takes nothing and returns nothing
//it prints out the data in the tree using pre order
void BSTB::printTreePre(){
	cout << "Print out pre order: " << endl;
	if(root == NULL){
		cout << "This tree is empty" << endl;
		return;
	} //if statement specifying what to do when the tree is empty
	else{
		printTreePre(root);
		cout << endl;
	} //else statement calling printTreePre(root) when the tree is not empty
}

//printTreePre(NodeTB *n)
//this function takes a pointer to a NodeTB (n) and returns nothing
//it recursively prints out the data in the tree using pre order starting at root n
void BSTB::printTreePre(NodeTB *n){
	if(n!=NULL){
		cout << n->data << " ";
		printTreePre(n->left);
		printTreePre(n->right);
	}//if statement traversing the tree using pre order when the root plugged in is not NULL
}

//printTreePost()
//this function takes nothing and returns nothing
//it prints out the data in the tree using post order
void BSTB::printTreePost(){
	cout << "Pring out post order: " << endl;
	if(root==NULL){
		cout << "This tree is empty" << endl;
		return;
	} //if statement specifying what to do when the tree is empty
	else{
		printTreePost(root);
		cout << endl;
	}//else statement calling printTreePost(root) when the tree is not empty
}

//printTreePost(NodeTB *n)
//this function takes a pointer to a NodeTB (n) and returns nothing
//it recursively prints out the data in the tree using post order starting at root n
void BSTB::printTreePost(NodeTB *n){
	if(n != NULL){
		printTreePost(n->left);
		printTreePost(n->right);
		cout<<n->data<< " ";
	}//if statement traversing the tree using post order when the root plugged in is not NULL
}

//search(string x)
//this function takes in a string (x) and returns a boolean value.
//it searches the tree for the string x and returns true if it is found.
//otherwise it returns false
bool BSTB::search(string x){
	if(root == NULL){
		cout << "This tree is empty" << endl;
		return false;
	}//if statement specifying what to do when the tree is empty
	else{
		return search(root, x);
	}//else statement calling search(root, x) when the tree is not empty
}

//search(NodeTB *n, string x)
//this function takes in a pointer to a NodeTB (n) and a string (x) and
//returns a boolean value.
//it recursively searches the tree for the string x and returns true if it is found.
//otherwise it returns false
bool BSTB::search(NodeTB *n, string x){
	if(n!=NULL){
		if(n->data == x){
			return true;
		} //if statement returning true if n's data is equal to x
		if(n->data > x){
			return search(n->left, x);
		} //if statement recursively calling this function, but using n's left child instead of n when n's data is greater than x
		if(n->data < x){
			return search(n->right, x);
		}//if statement recursively calling this function, but using n's right child instead of n when n's data is less than x
	}//if statement specifying what to do when n is not NULL
	return false;
}

//adjustBalances(NodeTB *n)
//this function takes in a pointer to a NodeTB (n) and returns nothing.
//it adjusts the heights of trees
void BSTB::adjustBalances(NodeTB *n){
	while(n->left->height-n->right->height > 1 || n->right->height-n->left->height > 1){
		if(n->right->height > n->left->height){
			rotateLeft(n);
		}//if statement rotating left to balance the tree if the height of n's right child is greater than the height of n's left child
		else{
			rotateRight(n);
		}//else statement rotating right to balance the tree if the height of n's left child is greater than the height of n's right child
	}//while loop iterating through while the difference between the height of n's right child and n's left child is greater than 1
}

//rotateRight(NodeTB *n)
//this function takes in a pointer to a NodeTB (n) and returns a NodeTB
//it performs a right rotation in order to balance an unbalanced tree/subtree
NodeTB *BSTB::rotateRight(NodeTB *n){
	NodeTB *x = n->left;
	NodeTB *tmp = x->right;
	x->right = n;
	n->left = tmp;
	if(n->left->height > n->right->height){
		n->height = n->left->height + 1;
	}//if statement updating n's height to be the height of its left child plus 1 if the height of its left child is greater than the height of its right child
	else{
		n->height = n->right->height + 1;
	}//else statement updating n's height to be the height of its right child plus 1 if the height of its right child is greater than the height of its left child
	if(x->left->height > x->right->height){
		x->height = x->left->height + 1;
	}//if statement updating x's height to be the height of its left child plus 1 if the height of its left child is greater than the height of its right child
	else{
		x->height = x->right->height + 1;
	}//else statement updating x's height to be the height of its right child plus 1 if the height of its right child is greater than the height of its left child
	return x;
}

//rotateLeft(NodeTB *n)
//this function takes in a pointer to a NodeTB (n) and returns a NodeTB
//it performs a left rotation in order to balance an unbalanced tree/subtree
NodeTB *BSTB::rotateLeft(NodeTB *n){
	NodeTB *x = n->right;
	NodeTB *tmp = x->left;
	x->left = n;
	n->right = tmp;
	if(n->left->height > n->right->height){
		n->height = n->left->height + 1;
	}//if statement updating n's height to be the height of its left child plus 1 if the height of its left child is greater than the height of its right child
	else{
		n->height = n->right->height + 1;
	}//else statement updating n's height to be the height of its right child plus 1 if the height of its right child is greater than the height of its left child
	if(x->left->height > x->right->height){
		x->height = x->left->height + 1;
	}//if statement updating x's height to be the height of its left child plus 1 if the height of its left child is greater than the height of its right child
	else{
		x->height = x->right->height + 1;
	}//else statement updating x's height to be the height of its right child plus 1 if the height of its right child is greater than the height of its left child
	return x;
}


