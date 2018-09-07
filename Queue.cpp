//Necessary header libraries.
#include "Queue.h"

//Queue data structure using doubly linked list. Enqueue and Dequeue operation occurs in constant time O(1).
//Enqueue operation is at the end of the linked list. Dequeue operation is at the start of the linked list.

//Function definition of dequeue.
void queue::dequeue() {

    //Return immediately if there are no elements in the queue.
    if(getCount() == 0){
        std::cout<<"Underflow state."<<std::endl;
        return;
    }

    linkedList::node *curr = head->next;

    //When only one element is left in the queue.
    if(head == tail)
        tail = nullptr;

    delete head;
    head = curr;

    //Decrease the count of number of element(s) in the stack.
    decrementCount();
}

//Function definition of front().
int queue::front() {
    return head == nullptr ? -1:head->data;
}

//Function definition of back().
int queue::back() {
    return tail == nullptr ? -1:tail->data;
}
