#pragma once
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

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
    const Elem& front() const ; // the front element
    void enqueue(const Elem& e);		// enqueue element at rear
    void dequeue() ;		// dequeue element at front
private:					// member data
    SLinkedList<Elem> S;				// circular list of elements
    int n;					// number of elements
};
#endif // !LINKEDQUEUE_H

template <typename E>
LinkedQueue<E>::LinkedQueue()			// constructor
    : S(), n(0) { }

template <typename E>
int LinkedQueue<E>::size() const			// number of items in the queue
{
    return n;
}

template <typename E>
bool LinkedQueue<E>::empty() const		// is the queue empty?
{
    return n == 0;
}
// get the front element
template <typename E>
const Elem& LinkedQueue<E>::front() const {
    if (empty())
        throw QueueEmpty("front of empty queue");
    return S.front();				// list front is queue front
}
// enqueue element at rear
template <typename E>
void LinkedQueue<E>::enqueue(const Elem& e) {
    S.add(e);					// insert after cursor
    S.advance();				// ...and advance
    n++;
}
// dequeue element at front
template <typename E>
void LinkedQueue<E>::dequeue() {
    if (empty())
        throw QueueEmpty("dequeue of empty queue");
    S.remove();					// remove from list front
    n--;
}