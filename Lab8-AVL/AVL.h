#ifndef AVL_H
#define AVL_H
#pragma once

#include "NodeInterface.h"
#include "AVLInterface.h"
#include "Node.h"

using namespace std;

class AVL: public AVLInterface {

protected:
	Node * root;

public:
	AVL(): root(NULL) {};
	 ~AVL() {
		 clear();
	 };

	NodeInterface * getRootNode() const;

	bool add(int data);
	bool remove(int data);
	void clear();

	bool recursive_add(Node*& currentNode, int data);
	bool recursive_remove(Node*& currentNode, int data);
	void recursive_clear(Node*& currentNode);
	int recursive_right(Node*& currentNode);

	void right_rotate(Node*& currentNode);
	void left_rotate(Node*& currentNode);
	void right_balance(Node*& currentNode);
	void left_balance(Node*& currentNode);
	
	int get_balance(Node*& currentNode);
	void balance(Node*& currentNode);

	int max(int a, int b);
};

#endif