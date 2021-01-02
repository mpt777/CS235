//#pragma once

#include "AVL.h"
#include "Node.h"
#include "NodeInterface.h"

using namespace std;


NodeInterface * AVL::getRootNode() const {
	return root;
}


bool AVL::add(int data) {
	recursive_add(root, data);
}

bool AVL::recursive_add(Node*& currentNode, int data) {
	//cout << currentNode->height << endl;

	if(currentNode == NULL) {
		currentNode = new Node(data);
		return true;
	} 

	else if (currentNode->data > data) {
		//recursive_add(currentNode->left, data);
		bool leftAdded = recursive_add(currentNode->left, data);
		if (leftAdded) {
			if (get_balance(currentNode) > 1)
				left_balance(currentNode);
			if (get_balance(currentNode) < -1)
				right_balance(currentNode);
		}
		return leftAdded;

	} else if (currentNode->data < data) {
		bool rightAdded = recursive_add(currentNode->right, data);
		if (rightAdded) {
			//cout << "here2" << endl;
			if (get_balance(currentNode) > 1) {
				left_balance(currentNode);
			}
			if (get_balance(currentNode) < -1) {
				right_balance(currentNode);
			}
		}
		return rightAdded;

	} else {
		if (get_balance(currentNode) > 1) {
			left_balance(currentNode);
			}
		if (get_balance(currentNode) < -1) {
			right_balance(currentNode);
		}
		return false;
	}
}


bool AVL::remove(int data) {
	recursive_remove(root, data);
}

int AVL::recursive_right(Node*& currentNode) {
		if(currentNode->right != NULL) {
			recursive_right(currentNode->right);
		} else {
			return currentNode->data;
		}
}	

bool AVL::recursive_remove(Node*& currentNode, int data) {
	if(currentNode==NULL) {
		return false;
	}

	if(currentNode->data == data) {
//only right child
		if(currentNode->right != NULL && currentNode->left == NULL) {
			Node* temp = currentNode;
			currentNode = currentNode-> right;
			balance(root);
			delete temp;
			return true;
//only left child
		} else if(currentNode->right == NULL && currentNode->left != NULL) {
			Node* temp = currentNode;
			currentNode = currentNode-> left;
			balance(root);
			delete temp;
			return true;
//leaf node
		} else if (currentNode->right == NULL && currentNode->left == NULL) {
			Node* temp = currentNode;
			currentNode = NULL;
			balance(root);
			delete temp;
			return true;

		} else {
			currentNode->data = recursive_right(currentNode->left);//rightmost vaule
			recursive_remove(currentNode->left,currentNode->data);
		}
	}
	else if(data < currentNode->data)	{ //finds the node we need
		recursive_remove(currentNode->left,data);
	} else if (data > currentNode->data) { 
		recursive_remove(currentNode->right,data);
	}
}

void AVL::clear() {
	recursive_clear(root);
	root = NULL;
	//delete root;
}

void AVL::recursive_clear(Node*& currentNode) {

	if (currentNode == NULL) {
		return;
	}
	if (currentNode->left != NULL) {
		recursive_clear(currentNode->left);
	} 
	if (currentNode->right != NULL) {
		recursive_clear(currentNode->right);
	} 
	if (currentNode->right == NULL && currentNode->left == NULL){
		delete currentNode;
	} else {
		delete currentNode;
	}
}

void AVL::right_balance(Node*& currentNode) {//rl and right heavy
	if (currentNode == NULL) {
		return;
	}
		if (get_balance(currentNode->left) >= 1) {
			left_rotate(currentNode->left);
		}
		right_rotate(currentNode);
}

void AVL::left_balance(Node*& currentNode) { //lr and left heavy
	if (currentNode == NULL) {
		return;
	}
	//cout << "balanceLeft" << endl;
		if (get_balance(currentNode->right) <= -1) {
			right_rotate(currentNode->right);
		}
		left_rotate(currentNode);
}


void AVL::right_rotate(Node*& currentNode) {//actually does the rotating
	Node* temp = currentNode->left;
	currentNode->left = temp->right;
	temp->right = currentNode;
	currentNode = temp;
}

void AVL::left_rotate(Node*& currentNode) {
	Node* temp = currentNode->right;
	currentNode->right = temp->left;
	temp->left = currentNode;
	currentNode = temp;
}

void AVL::balance(Node*& currentNode) {
	if (currentNode == NULL) {
		return;
	}
	if (get_balance(currentNode) > 1) {
		left_balance(currentNode);
	}
	else if (get_balance(currentNode) < -1) {
		right_balance(currentNode);
	}
		balance(currentNode->left);
		balance(currentNode->right);
}

int AVL::get_balance(Node*& currentNode) {
	int leftTemp;
	int rightTemp;

  if(currentNode == NULL){
  	return 0;
	}	else {

		int right;
		int left;

		if (currentNode->right != NULL) {
			right = currentNode->right->getHeight();
		}
		else {
		right = 0;
		}

		if (currentNode->left != NULL) {
			left = currentNode->left->getHeight();
		}
		else {
			left = 0;
		}
		return right - left;
	}
}