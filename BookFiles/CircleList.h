

class CircleList {				// a circularly linked list
public:
    CircleList();				// constructor
    ~CircleList();				// destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;			// element at cursor
    const Elem& back() const;			// element following cursor
    void advance();				// advance cursor
    void add(const Elem& e);			// add after cursor
    void remove();				// remove node after cursor
private:
    CNode* cursor;				// the cursor 
};


