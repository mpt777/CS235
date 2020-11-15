//#pragma once

#include "BST.h"
#include "Node.h"
#include "NodeInterface.h"

using namespace std;

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/

NodeInterface * BST::getRootNode() const {
	return root;
}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
bool BST::add(int data) {
	    /*
	    Node *ptr = new Node(data);
	    ptr->left = NULL; // To test that the friend relationship works
	    NodeInterface *rval = ptr->getLeftChild();
	    long value = (long)rval;
	    cout << "Added "<<data<<endl;
	    root = ptr;
			*/

	//cout << "add"<<endl;
	recursive_add(root, data);
	//cout << "Added "<<data<<endl;
}

bool BST::recursive_add(Node*& currentNode, int data) {
	if(currentNode == NULL) {
		currentNode = new Node(data);
		return true;
	} 
	else if (currentNode->data > data) {
		recursive_add(currentNode->left, data);
	} else if (currentNode->data < data) {
		recursive_add(currentNode->right, data);
	} else {
		return false;
	}

}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/

bool BST::remove(int data) {
	recursive_remove(root, data);
}

int BST::recursive_right(Node*& currentNode) {
		if(currentNode->right != NULL) {
			recursive_right(currentNode->right);
		} else {
			return currentNode->data;
		}
}	

bool BST::recursive_remove(Node*& currentNode, int data) {
	if(currentNode==NULL) {
		return false;
	}

	if(currentNode->data == data) {
//only right child
		if(currentNode->right != NULL && currentNode->left == NULL) {
			Node* temp = currentNode;
			currentNode = currentNode-> right;
			delete temp;
			return true;
//only left child
		} else if(currentNode->right == NULL && currentNode->left != NULL) {
			Node* temp = currentNode;
			currentNode = currentNode-> left;
			delete temp;
			return true;
//leaf node
		} else if (currentNode->right == NULL && currentNode->left == NULL) {
			Node* temp = currentNode;
			currentNode = NULL;
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
	/*
Node * old_root;
Node * new_root;
Node * lagging_new_root;
Node * old_root_left;
Node * new_root_left;

Node * temp;

cout << data << " -- " << currentNode->data << endl;

	if(currentNode->data == data) {
		old_root = currentNode;

		if(currentNode->left == NULL){
			old_root_left = old_root;	
		} else {
			old_root_left = currentNode->left;
		}

		if(old_root_left->right == NULL) {
			new_root = old_root_left;
		} else {
			lagging_new_root = recursive_right(old_root_left);
			new_root = lagging_new_root->right;
		}
		
		old_root->data = new_root->data; //makes the new root and the old root equal
		
		if(new_root->left == NULL) { // if there are no children left, delete
			lagging_new_root->right = NULL; 
			delete new_root;
			return true;

		} 
		else if (old_root->left != NULL) {
			cout << "here2" << endl;
			cout << old_root->left->data << " || " << old_root->left->left->data << endl;

			temp = old_root->left;
			delete old_root->left;

			old_root->left = temp->left;

			//pulls the left root up to the current spot
			return true;
		} 
		else if (old_root->left == NULL) {
			cout << "Here3" << endl;
			cout << old_root->data << " || " << old_root->right->data << endl;
			old_root = old_root->right;
			delete old_root->right;
			return true;
		}
	} 
	else if (currentNode->data > data  && currentNode->left != NULL) {
		recursive_remove(currentNode->left, data);
	} else if (currentNode->data < data &&  currentNode->right != NULL) {
		recursive_remove(currentNode->right, data);
	} else {
		return false;
	}
	*/

}

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
void BST::clear() {
	recursive_clear(root);
	root = NULL;
	//delete root;
}

void BST::recursive_clear(Node*& currentNode) {

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

/*
		cout <<root->right->right->right->right->right->right->data << "E"<< endl;
		cout <<root->right->right->right->right->right->right->left->data << "T"<< endl;
		cout << currentNode->data << endl;
*/