TARGETS = bst
CC = g++
CCFLAGS = -std=c++11 -g
bst: main.cpp BSTInterface.h NodeInterface.h BST.h BST.cpp Node.h Node.cpp
	$(CC) $(CCFLAGS) -o bst main.cpp BST.cpp Node.cpp