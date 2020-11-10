LinkedQueue::LinkedQueue()			// constructor
    : C(), n(0) { }

int LinkedQueue::size() const			// number of items in the queue
{
    return n;
}

bool LinkedQueue::empty() const		// is the queue empty?
{
    return n == 0;
}
// get the front element
const Elem& LinkedQueue::front() const throw(QueueEmpty) {
    if (empty())
        throw QueueEmpty("front of empty queue");
    return C.front();				// list front is queue front
}

// insert new first element
void LinkedDeque::insertFront(const Elem& e) {
    D.addFront(e);
    n++;
}
// insert new last element
void LinkedDeque::insertBack(const Elem& e) {
    D.addBack(e);
    n++;
}
// remove first element
void LinkedDeque::removeFront() throw(DequeEmpty) {
    if (empty())
        throw DequeEmpty("removeFront of empty deque");
    D.removeFront();
    n--;
}
// remove last element
void LinkedDeque::removeBack() throw(DequeEmpty) {
    if (empty())
        throw DequeEmpty("removeBack of empty deque");
    D.removeBack();
    n--;
}