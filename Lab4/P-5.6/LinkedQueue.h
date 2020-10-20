#pragma once
#include "SLinkedList.h"
#include "QueueEmpty.h"
#include <string>
typedef std::string Elem;				// queue element type
template <typename E>
class LinkedQueue {				// queue as doubly linked list
public:
    LinkedQueue();				// constructor
    int size() const;				// number of items in the queue
    bool empty() const;				// is the queue empty?
    const Elem& front() const throw(QueueEmpty); // the front element
    void enqueue(const Elem& e);		// enqueue element at rear
    void dequeue() throw(QueueEmpty);		// dequeue element at front
private:					// member data
    SLinkedList<Elem> S;				// circular list of elements
    int n;					// number of elements
};