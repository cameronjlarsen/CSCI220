#pragma once
template <typename T>
class Node
{
private:
    T elem;                 // linked list elem value
    Node<T>* next;          // next item in list
    template<typename E>
    friend class LinkedList;
};