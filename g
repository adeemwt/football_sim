#ifndef __LLIST_H
#define __LLIST_H

#include <iostream>

// Forward declaration
template<class T>
class Node
{
public :
	Node(T input) :val(T) {}
	Node() :val(NULL) {}

private:
	T val;
};
template<class T>
class LinkedList 
{
public:
	// c-tors, d-tors
	LinkedList() { base = new Node(); }
	~LinkedList() { delete base; }
	// Operators

	// Methods
	// Method Overrides

private:
	Node* cur;
	Node* base;
	Node* List;
};


#endif
