#include "LinkedQueue.h"

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

