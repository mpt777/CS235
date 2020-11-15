#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "NodeInterface.h"

class Node: public NodeInterface {

public:

		int data;
		Node * left;
  	Node * right;

  	Node(int& the_data, 
         Node * left_val = NULL,
         Node * right_val = NULL) : 
    data(the_data), left(left_val),  right(right_val) {};

	Node() {}
		~Node() {}
	
	int getData() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;

};

#endif