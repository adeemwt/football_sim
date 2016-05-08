#ifndef __LLIST_H
#define __LLIST_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<class T>
class Node
{


public:
	Node<T>* next;
	T val;
	Node<T>(T input) :val(input) ,next(NULL){}
	Node<T>() :val(NULL) ,next(NULL){}
	Node<T>& operator=( Node<T>&);

};
template<class T>
class LinkedList
{
	Node<T> *head;
	Node<T> *tail;
public:
	// c-tors, d-tors
	LinkedList() { head = new Node<T>(); tail = new Node<T>(); head->next = tail; }
	~LinkedList() { }
	// Operators

	// Methods
	T pop_back(void) {
		T res = tail->val;
	Node<T>* old_tail = tail;

		// Traverse the list to node just before tail
			Node<T>* current = head;
			while (current->next != tail) {
				current = current->next;
			}

			// Unlink and reposition
			current->next = NULL;
			tail = current;
		
		return res;

	}
	void push_back(T d) {

		Node<T>* new_tail = new Node<T>(d);
		tail->next = new_tail;
		tail = new_tail;
	}
	// Method Overrides

};


#endif
