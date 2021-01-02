//#pragma once
#include "Node.h"

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
int Node::getData() const {
	return data;
}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
NodeInterface * Node::getLeftChild() const {
	return left;
}


	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
NodeInterface * Node::getRightChild() const {
	return right;
}

int Node::getHeight() {
		int leftHeight = 0;
		int rightHeight = 0;

		if (left != NULL)
		{
			leftHeight = left->getHeight();
		}
		if (right != NULL)
		{
			rightHeight = right->getHeight();
		}
		return max(leftHeight, rightHeight) + 1;
}
/*
	int Node::getBalance() {
		int r;
		int l;

		if (r != NULL) {
			r = right->getHeight();
		}
		else
		right = 0;

		if (l != NULL) {
			l = left->getHeight();
		}
		else
		l = 0;

		return right - left;
	}
	*/