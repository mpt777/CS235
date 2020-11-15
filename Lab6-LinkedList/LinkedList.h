//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList: public LinkedListInterface<T> {

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& the_data, Node* next_val = NULL) :
                data(the_data) {next = next_val;}
    };

    Node *mylist;
    Node* head;
    Node* tail;
    int num_items;

public:

    LinkedList(void) {
        mylist = NULL;
        num_items = 0;
        head = nullptr;
        tail = nullptr;
				tail = nullptr;
    };
    virtual ~LinkedList(void) {
        clear();
    };


    /*
    insertHead

    A node with the given value should be inserted at the beginning of the list.

    Do not allow duplicate values in the list.
    */
    virtual void insertHead(T value) {
        cout << "In Inserting" << endl;

        if (num_items == 0) {
					Node *ptr = new Node(value);
					ptr->next = NULL;
					head = ptr;
					tail = ptr;
					num_items++;
					return;
        }

			if (!(isDuplicate(value))) {
				Node *ptr = new Node(value);
				ptr->next = head;
				head = ptr;
				num_items++;
				return;
			}
    };

    /*
    insertTail

    A node with the given value should be inserted at the end of the list.

    Do not allow duplicate values in the list.
    */
    virtual void insertTail(T value){
			if (num_items == 0) {
				Node *ptr = new Node(value);
				ptr->next = NULL;
				head = ptr;
				tail = ptr;
				num_items++;
				return;
			}
			if (!(isDuplicate(value))) {
				Node *ptr = new Node(value);
				tail->next = ptr;
				tail = ptr;
				ptr->next = NULL;
				num_items++;
				return;
			}
		//cout << "In Test5" << endl;
    };

    /*
    insertAfter

    A node with the given value should be inserted immediately after the
    node whose value is equal to insertionNode.

    A node should only be added if the node whose value is equal to
    insertionNode is in the list. Do not allow duplicate values in the list.
    */
    virtual void insertAfter(T value, T insertionNode) {
			if (num_items == 0) {
				return;
			}
			Node *temp;
			temp = head;
			if (!(isDuplicate(value))) {
				while (temp->next != NULL) {
				if (temp->data == insertionNode) {
					Node *ptr = new Node(value);
					ptr->next = temp->next;
					temp->next = ptr;
					num_items++;
					return;
				}
				temp = temp->next;
			}

			if (temp == tail && temp->data == insertionNode) {
				Node *ptr = new Node(value);
				tail->next = ptr;
				ptr->next = NULL;
				tail = ptr;
				num_items++;
				return;
			}
		}
	};

    /*
    remove

    The node with the given value should be removed from the list.

    The list may or may not include a node with the given value.
    */
    virtual void remove(T value) {
			Node *temp;
			Node *lagging_temp;
			temp = head;

			if (num_items == 0) {
				return;
			}

			if(head->data == value) {
				head = temp->next;
				delete temp;
				num_items--;
				return;
			}

			while (temp->data != value) {
				lagging_temp = temp;
				temp = temp->next;
				if(temp->next == NULL) {
					break;
				}
			}
			

			if(temp->data == value && temp->next == NULL){
				tail = lagging_temp;
				tail->next = NULL;
				delete temp;
				num_items--;
				return;
			}
			
			//******* NEED TO FIND A WAY TO REMOVE A VALUE WHEN IT IS THE LAST IN THE LINKED LIST

			if(temp->next !=NULL) {
				lagging_temp->next = temp->next;
				num_items--;
				delete temp;
			}

		};

    /*
    clear

    Remove all nodes from the list.
    */
    virtual void clear() {
			Node *temp;
			Node *lagging_temp;
			temp = head;

			if (num_items == 0) {
				return;
			}

			while (temp->next != NULL) {
				lagging_temp = temp;
				temp = temp->next;
				delete lagging_temp;
			}
			delete temp;
			head = nullptr;
			tail = nullptr;
			num_items = 0;
    };

    /*
    at

    Returns the value of the node at the given index. The list begins at
    index 0.

    If the given index is out of range of the list, throw an out of range exception.
    */
    virtual T at(int index) {
			Node *temp;
			temp = head;

			cout << num_items << endl;

			if (num_items == 0 || index+1 > num_items || index < 0) {
				throw out_of_range("out_of_range");
			}

			int count = 0;
			cout << temp->data << endl;
			while (count != index) {
				temp = temp->next;
				count++;
			}
			return(temp->data);
    };

    /*
    size

    Returns the number of nodes in the list.
    */
    virtual int size() {
      return(num_items);
    };

    /*
    toString

    Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
    There should be no trailing space at the end of the string

    For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
    "1 2 3 4 5"
    */
    virtual string toString() {
			if (num_items == 0 ){
				return("");
			}
      stringstream ss;
      for(Node *ptr = head; ptr != NULL; ptr = ptr->next){
				ss << ptr->data << " ";
      }
			string temp_string = ss.str();
			temp_string.pop_back();
      return(temp_string);
    };

  	virtual bool isDuplicate(T value) {
        Node *temp = head;
      while (temp->data != value) {
        if (temp->next == NULL) {
          return false;
        }
        temp = temp->next;
      }
      return true;
    };

};
