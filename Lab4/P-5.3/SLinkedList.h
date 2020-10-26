#pragma once
#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "SNode.h"
template <typename E>
class SLinkedList {				// a singly linked list
public:
	SLinkedList();				// empty list constructor
	~SLinkedList();				// destructor
	bool empty() const;			// is list empty?
	const E& front() const;		// return front element
	void addFront(const E& e);	// add to front of list
	void removeFront();			// remove front item list
    void addRear(const E& e);   // add to rear of list
private:
	SNode<E> *head;				// head of the list
};
#endif // !SLINKEDLIST_H
template <typename E>
SLinkedList<E>::SLinkedList()				// constructor
    : head(nullptr) { }

template <typename E>
bool SLinkedList<E>::empty() const			// is list empty?
{
    return head == nullptr;
}

template <typename E>
const E& SLinkedList<E>::front() const		// return front element
{
    return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList()			// destructor
{
    while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {		// add to front of list
    SNode<E>* temp = new SNode<E>;				// create new node
    temp->elem = e;					            // store data
    temp->next = head;					        // head now follows temp
    head = temp;						        // temp is now the head
}

template <typename E>
void SLinkedList<E>::removeFront() {			// remove front item
    SNode<E>* old = head;				        // save current head
    head = old->next;					        // skip over old head
    delete old;						            // delete the old head
}

template<typename E>
void SLinkedList<E>::addRear(const E& e)
{
    SNode<E>* temp = new SNode<E>;    // create new node for new element
    SNode<E>* last = head;            // new node to locate end of list
    temp->elem = e;                   // store data
    temp->next = nullptr;             // new node will be end so point it to null
  
    if (empty()) {
        head = temp;              // if list is empty point head to temp
        return;
    }
    else {                         // traverse list till the last node
        while(last->next != nullptr)
        last = last->next;          
        last->next = temp;          // change the next of last node
        return;
    }
}