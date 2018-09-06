//Necessary header libraries.
#include "LinkedList.h"

//Function definition for creating node and adding it to the linked list.
void linkedList::createNode(int val) {

    //Allocating memory for the new node.
    auto *newNode = new node;

    //the node is always going to be added at the end so the next pointer is always pointing to null.
    newNode->data = val;
    newNode->next = nullptr;

    //Check if the list is empty. Could have used getCount()==0 as a condition as well.
    if(head == nullptr){
        head = newNode;
        newNode->prev = nullptr;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
    }

    //Set the newly added element as tail.
    tail = newNode;
}