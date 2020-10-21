template <typename A>
class SNode {					        // singly linked list node
private:
    A elem;					            // linked list element value
    SNode<A>* next;	                // next item in the list
    template<typename E>
    friend class SLinkedList;		    // provide SLinkedList access
};