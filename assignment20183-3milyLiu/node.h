#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists

template<typename T>
class Node{
public:
    T data;
    Node* next;
    Node* previous;

    Node():
    next(nullptr),
    previous(nullptr){}
    Node(T d):
    data(d),
    next(nullptr),
    previous(nullptr){}

    //Node* head = nullptr;
    //Node* tail = nullptr;
};

template<typename T>
class NodeIterator {
public:
    Node<T>* current;

    NodeIterator(Node<T>* currentIn)
        : current(currentIn) {        
    }

    T & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here

    void operator++(){
        current = current->next;
    }
    void operator++(int){
        current = current->next;
    }
   /* NodeIterator operator++(){
        NodeIterator next = *this;
        ++(*this);
        return next;
    }*/
    bool operator==(const NodeIterator& nodeIterator)const{
        return current == nodeIterator.current;
    }
    bool operator!=(const NodeIterator& nodeIterator)const{
        return current != nodeIterator.current;
    }
};

// do not edit below this line

#endif
