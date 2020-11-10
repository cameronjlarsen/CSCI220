template <typename E> ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1) { }	// constructor from capacity

template <typename E> int ArrayStack<E>::size() const
{
    return (t + 1);
}				// number of items in the stack

template <typename E> bool ArrayStack<E>::empty() const
{
    return (t < 0);
}				// is the stack empty?

template <typename E>				// return top of stack
const E& ArrayStack<E>::top() const throw(StackEmpty) {
    if (empty()) throw StackEmpty("Top of empty stack");
    return S[t];
}

template <typename E>				// push element onto the stack
void ArrayStack<E>::push(const E& e) throw(StackFull) {
    if (size() == capacity) throw StackFull("Push to full stack");
    S[++t] = e;
}

template <typename E>				// pop the stack
void ArrayStack<E>::pop() throw(StackEmpty) {
    if (empty()) throw StackEmpty("Pop from empty stack");
    --t;
}

class StackEmpty : public RuntimeException {
public:
    StackEmpty(const string& err) : RuntimeException(err) {}
};