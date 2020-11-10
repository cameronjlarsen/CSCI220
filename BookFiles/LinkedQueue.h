typedef string Elem;				// queue element type
class LinkedQueue {				// queue as doubly linked list
public:
    LinkedQueue();				// constructor
    int size() const;				// number of items in the queue
    bool empty() const;				// is the queue empty?
    const Elem& front() const throw(QueueEmpty); // the front element
    void enqueue(const Elem& e);		// enqueue element at rear
    void dequeue() throw(QueueEmpty);		// dequeue element at front
private:					// member data
    CircleList C;				// circular list of elements
    int n;					// number of elements
};
