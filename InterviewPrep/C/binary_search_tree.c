/*
Question 6: Binary Search Tree (BST) Implementation
Description:

Implement a binary search tree (BST) in C with the following operations:
Insertion of a new value.
Deletion of a node by value.
In-order traversal to print the tree.
Finding the height of the tree.
Key Concepts:

Structs in C.
Recursive functions.
Dynamic memory allocation.
Understanding of binary search tree properties.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int value;
    struct BSTNode* left;
    struct BSTNode* right; 
} BSTNode;

void initBST(BSTNode** node, int val) {
    *node = (BSTNode*) malloc(sizeof(BSTNode));
    (*node)->value = val;
    (*node)->left = NULL;
    (*node)->right = NULL;
}

void insertBST(const BSTNode** node, int val) {
    if (*node == NULL) {
        initBST(&(node), val);
        return;
    }
    BSTNode* curr = *node;
    if (val < curr->value) {
        if (curr->left == NULL) {
            initBST(&(curr->left), val);
            return;
        }
        insertBST(&(curr->left), val);
    } else {
        if (curr->right == NULL) {
            initBST(&(curr->right), val);
            return;
        }
        insertBST(&(curr->right), val);
    }
}

struct Node

void deleteBST(BSTNode** node, int val){
    if (*node == NULL) {
        return;
    }   
    if ((*node)->value == val) {
        // Found node, start deletion
        if ((*node)->left == NULL && (*node)->right == NULL) {
            // no children
            free(*node);
            return;
        } else if ((*node)->left != NULL && (*node)->right != NULL) {
            // two children
        } else {
            // on child
            BSTNode* temp = *node;
            *node = ((*node)->left != NULL) ? (*node)->left : (*node)->right;
            free(temp);
        }
    } else if (val < (*node)->value) {
        deleteBST(&((*node)->left), val);
    } else {
        deleteBST(&((*node)->right), val);
    }
}