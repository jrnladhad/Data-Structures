//Necessary header libraries.
#include "LinkedList.h"
#include "Stack.h"

//Stack data structure using doubly linked list. Pushing and popping elements occur in constant time, O(1).
//Pushing and Popping both occur at the end of the linked list.

//Function definition of pop().
void stack::pop() {

    //Return immediately if there are no elements in the queue.
    if(getCount() == 0){
        std::cout<<"Underflow state."<<std::endl;
        return;
    }

    linkedList::node *curr = tail->prev;

    //Check if only one element is left and setting both head and tail back to null.
    if (tail == head)
        head = nullptr;

    tail = curr;
    delete tail;

    //Decrease the count of number of element(s) in the stack.
    decrementCount();

}

//Function definition of top().
int stack::top() {
    return tail == nullptr ? -1 : tail->data;
}

