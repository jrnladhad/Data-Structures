#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

//Necessary header libraries.
#include <iostream>
#include "LinkedList.h"

//Derived class, queue which inherits from linkedList.
class queue: private linkedList{
private:

    //Keeps a count of the number of elements in the stack.
    int count = 0;

    //Functions to manipulate the value of count.
    void incrementCount() {count++;}
    void decrementCount() {count--;}

public:

    //Inserts data into queue.
    void enqueue(int val) {createNode(val); incrementCount();}

    //Removes data from queue.
    void dequeue();

    //Returns the start of the queue.
    int front();

    //Returns the end of the queue.
    int back();

    //Returns the count of elements in the queue.
    int getCount() {return count;}
};

#endif //DATA_STRUCTURES_QUEUE_H
