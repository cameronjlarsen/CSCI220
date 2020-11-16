#pragma once
#include "Node.h"

template <typename E>
class LinkedList {				// a singly linked list
public:
    LinkedList();				// empty list constructor
    ~LinkedList();				// destructor
    bool empty() const;				// is list empty?
    const E& front() const;			// return front element
    void addFront(const E& e);			// add to front of list
    void removeFront();				// remove front item list
private:
    Node<E>* head;				// head of the list
};

template<typename E>
inline LinkedList<E>::LinkedList()
: head(nullptr) {}

template<typename E>
inline LinkedList<E>::~LinkedList()
{
    while (!empty()) removeFront();
}

template<typename E>
inline bool LinkedList<E>::empty() const
{
    return head == nullptr;
}

template<typename E>
inline const E& LinkedList<E>::front() const
{
    return head->elem;
}

template<typename E>
inline void LinkedList<E>::addFront(const E& e)
{
    Node<E>* v = new Node<E>;
    v->elem = e;
    v->next = head;
    head = v;
}

template<typename E>
inline void LinkedList<E>::removeFront()
{
    Node<E>* old = head;
    head = old->next;
    delete old;
}
