#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

// Do not add any #include statements here.  If you have a convincing need for adding a different #include please post in the forum on KEATS.

// TODO your code goes here:
#include <initializer_list>
using namespace std;
template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int count;
public:
   LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    LinkedList(initializer_list<T> l):
    head(nullptr),
    tail(nullptr),
    count(0){
        for(const T &item:l){
            push_back(item);
        }
    }

    void push_front(T const& stuff){
        Node<T> *newNode = new Node<T>(stuff);
        if(count > 0) {
            newNode->next = head;
            head->previous = newNode;
        }
        else{
            tail = newNode;
        }
        head = newNode;
    ++count;
    }

    T& front()const
    {
        return head->data;
    }

    void push_back(T const& stuff){
        Node<T> * last = new Node<T>(stuff);
        if(head == nullptr){
            head = last;
        }
        else{
            last -> previous = tail;
            tail -> next = last;
        }
        tail = last;
        ++count;
    }

    T& back()const{
        return tail -> data;
    }

    int size()const{
        return count;
    }

    NodeIterator<T>begin() const {
        return NodeIterator<T>(head);
    }

    NodeIterator<T>end(){
        return NodeIterator<T>(tail->next);
    }

    void reverse(){
        Node<T>*current = head;
        //Node<T>*prev = nullptr, *next = nullptr;
        while(current != nullptr){
            Node<T>*x = current->next;
            current->next = current->previous;
            current->previous = x;
            current = current->previous;
        }
        current = head;
        head = tail;
        tail = current;
    }

    NodeIterator<T>& insert(NodeIterator<T>& ittr,const T& stuff){
        T old = ittr.current->data;
        ittr.current->data = stuff;
        Node<T>* newNode = new Node<T>(old);
        newNode->next = ittr.current->next;
        newNode->previous = ittr.current;
        if(tail==ittr.current){
            tail = newNode;
        }
        else{
            ittr.current->next->previous = newNode;
        }
        ittr.current->next = newNode;
        ++count;
        return ittr;
    }

    NodeIterator<T>& erase(NodeIterator<T>& ittr){
        Node<T>* erase = ittr.current;
        if(head==ittr.current){
            head = erase->next;
            head->previous = nullptr;
        }
        else if(tail==ittr.current){
            tail = erase->previous;
            tail->next = nullptr;
        }
        else{
            erase->next->previous = erase->previous;
            erase->previous->next = erase->next;
        }
        --count;
        ++ittr;
        delete erase;
        return ittr;
    }

   ~LinkedList(){
       Node<T>*current = head;
       while(current != nullptr){
           Node<T> *next = current->next;
           delete current;
           current = next;
       }
       head = nullptr;
   }
};

// do not edit below this line

#endif