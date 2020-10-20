template <typename E>
class SNode {					// singly linked list node
private:
    E elem;					// linked list element value
    SNode<E>* next;				// next item in the list
    friend class SLinkedList<E>;		// provide SLinkedList access
};