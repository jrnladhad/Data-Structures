#ifndef DATA_STRUCTURES_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_BINARYSEARCHTREE_H

//Necessary header libraries.
#include <iostream>

namespace BST{
    class binarySearchTree{
    private:

        //Structure definition for nodes of the binary search tree.
        struct bstNodes{
            int data;
            bstNodes *right;
            bstNodes *left;
        };

        //Root of the binary search tree.
        bstNodes *root;

        //Utility functions for user functions.
        bstNodes *insertUtil(bstNodes *, int);
        bool searchUtil(bstNodes *, int);
        void inorderUtil(bstNodes *);
        int minUtil(bstNodes *);
        int maxUtil(bstNodes *);
        bstNodes *minNodeUtil(bstNodes *);
        bstNodes *removeUtil(bstNodes *, int);

    public:
        //Constructor for setting the root to null immediately after the creation of object.
        binarySearchTree() {root = nullptr;}

        //User function.
        void insert(int);
        bool search(int);
        void inorder();
        int min();
        int max();
        void remove(int);
    };
}


#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
