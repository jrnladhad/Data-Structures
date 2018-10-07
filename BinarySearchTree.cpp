//Necessary header libraries.
#include "BinarySearchTree.h"

//Binary Search Tree data structure.
//Time complexity: a. Insertion - Worst case: O(n)
//                                Best case: O(log n)
//                 b. Search - Worst case: O(n)
//                             Best case: O(log n)
//                 c. Deletion - Worst case: O(n)
//                               Best case: O(log n)

using namespace BST;

//Utility function for insertion of elements into binary search tree.
binarySearchTree::bstNodes* binarySearchTree::insertUtil(binarySearchTree::bstNodes *curr, int val) {
    if(curr == nullptr){
        curr = new binarySearchTree::bstNodes;
        curr->data = val;
        curr->left = curr->right = nullptr;
    }
    else val < curr->data ? (curr->left = insertUtil(curr->left, val)) : (curr->right = insertUtil(curr->right, val));
    return curr;
}

//Utility function for searching an element.
bool binarySearchTree::searchUtil(binarySearchTree::bstNodes *curr, int x) {
    if(curr == nullptr)
        return false;
    if(x < curr->data)
        return searchUtil(curr->left, x);
    if(x > curr->data)
        return searchUtil(curr->right, x);
    return true;
}

//Utility function for printing the binary search tree in inorder sequence.
void binarySearchTree::inorderUtil(binarySearchTree::bstNodes *root) {
    if(root == nullptr)
        return;
    inorderUtil(root->left);
    std::cout<<root->data<<"\t";
    inorderUtil(root->right);
}

//Utility function for finding minimum value of the binary search tree.
int binarySearchTree::minUtil(binarySearchTree::bstNodes *root) {
    if(root->left == nullptr)
        return root->data;
    return minUtil(root->left);
}

//Utility function for finding maximum value of the binary search tree.
int binarySearchTree::maxUtil(binarySearchTree::bstNodes *root) {
    if(root->right == nullptr)
        return root->data;
    return maxUtil(root->right);
}

//Utility function for finding the address of the smallest value node.
binarySearchTree::bstNodes* binarySearchTree::minNodeUtil(binarySearchTree::bstNodes *root) {
    if(root->left == nullptr)
        return root;
    return minNodeUtil(root->left);
}

//Utility function for removing the given value, if found.
binarySearchTree::bstNodes* binarySearchTree::removeUtil(binarySearchTree::bstNodes *root, int key) {

    //Base case.
    if(root == nullptr)
        return root;

    //Find the value in the left subtree.
    else if(key < root->data)
        root->left = removeUtil(root->left, key);

    //Find the value in the right subtree.
    else if(key > root->data)
        root->right = removeUtil(root->right, key);

    //Once value is found then delete that node and restructure the tree.
    else{

        //Node with only one child or no child.
        if(root->left == nullptr){
            binarySearchTree::bstNodes *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            binarySearchTree::bstNodes *temp = root->left;
            delete root;
            return temp;
        }

        //If both the child's exist. Then find the smallest value in the right subtree.
        binarySearchTree::bstNodes *temp = minNodeUtil(root->right);

        //Copy the inorder's successor to the root.
        root->data = temp->data;

        //Remove the copied node.
        root->right = removeUtil(root->right, temp->data);
    }
    return root;
}

//User function for inserting element.
void binarySearchTree::insert(int val) {
    root = insertUtil(root, val);
}

//User function for searching element.
//Returns true or false.
bool binarySearchTree::search(int x) {
    return searchUtil(root, x);
}

//User function for printing inorder sequence.
void binarySearchTree::inorder() {
    inorderUtil(root);
}

//User function for finding the smallest value in binary search tree.
//Returns the minimum value.
int binarySearchTree::min() {
    return minUtil(root);
}

int binarySearchTree::max() {
    return maxUtil(root);
}

//User function for removing the desired value.
void binarySearchTree::remove(int key) {
    root = removeUtil(root, key);
}