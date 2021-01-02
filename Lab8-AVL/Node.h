#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "NodeInterface.h"

class Node: public NodeInterface {

public:

		int data;
		Node * left;
  	Node * right;
		int height = 0;

  	Node(int& the_data, 
         Node * left_val = NULL,
         Node * right_val = NULL,
				 int the_height = 0) : 
    data(the_data), left(left_val),  right(right_val), height(the_height) {};

	Node() {}
		~Node() {}
	
	int getData() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
	int getHeight();
	//int getBalance();

};

#endif