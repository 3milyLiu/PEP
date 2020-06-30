#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>

/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {
private:
    SimpleVector<char>buffer;
    int front = 0, rear = 0, maxSize;
public:
    CircularBuffer(int maxIn):
    buffer(maxIn),maxSize(maxIn){}
    int count()const{
        return ((rear - front + maxSize) % maxSize);
    }
    bool full()const{
        return(count()==(maxSize-1));
    }
    void add(char c){
        buffer[rear] = c;
        rear = (rear+1)%maxSize;
    }
    char remove(){
        char removed;
        removed = buffer[front];
        front = (++front)%maxSize;
        return removed;
    }
    };

// don't write any code below this line

#endif
