#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H

namespace LL{
    class linkedList{
    protected:

        //Node structure for creating a linked list.
        struct node{
            int data;
            node *next;
            node *prev;
        };

        //Needs to be protected because they need to be accessed only by the base class and the derived class(es).
        node *head, *tail;

        //Constructor for initializing head and tail pointer.
        linkedList(): head(nullptr), tail(nullptr) {}

        //Creates new nodes that are going to be added to the list.
        void createNode(int);
    };
}


#endif //DATA_STRUCTURES_LINKEDLIST_H
