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

BSTNode* insert(BSTNode* node, int val) {
    if (node == NULL) {
        BSTNode* newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->value = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (val < node->value) {
        node->left = insert(node->left, val);
    } else if (val > node->value) {
        node->right = insert(node->right, val);
    }
    return node;
}

void inOrderTraversal(BSTNode* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d ", node->value);
    inOrderTraversal(node->right);
}


BSTNode* deleteNode(BSTNode* node, int val) {
    if (node == NULL) {
        return node;
    }

    if (node->value == val) {
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
        } else if (node->left != NULL && node->right != NULL) {
            // find next node to replace
            // inorder successor
            BSTNode* temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }

            node->value = temp->value;

            node->right = deleteNode(node->right, temp->value);
            
        } else if (node->left != NULL) {
            BSTNode* temp = node;
            node = node->left;
            free(temp);
        } else {
            BSTNode* temp = node;
            node = node->right;
            free(temp);
        }
    } else if (val < node->value) {
        node->left = deleteNode(node->left, val);
    } else {
        node->right = deleteNode(node->right, val);
    }
    return node;
}

int findHeight(BSTNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
}

int main() {
    BSTNode* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Height of the tree: %d\n", findHeight(root));

    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20:\n");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30:\n");
    inOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("In-order traversal after deleting 50:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}