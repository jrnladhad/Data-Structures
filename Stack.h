#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

//Necessary header libraries.
#include <iostream>
#include "LinkedList.h"
namespace STACK{
    class stack: private LL::linkedList{
    private:

        //Keeps a count of the number of elements in the stack.
        int count = 0;

        //Functions to manipulate the value of count.
        void incrementCount() {count++;}
        void decrementCount() {count--;}

    public:

        //Inserts data into stack.
        void push(int val) {createNode(val); incrementCount();}

        //Deletes data from stack.
        void pop();

        //Returns the top of the stack.
        int top();

        //Returns the number of elements in the stack.
        int getCount() {return count;}
    };
}



#endif //DATA_STRUCTURES_STACK_H
