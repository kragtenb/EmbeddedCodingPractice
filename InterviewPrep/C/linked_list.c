/*
Question 5: Implement a Linked List
Description:

Implement a singly linked list in C with the following operations:
Insert at the beginning.
Insert at the end.
Delete a node by value.
Reverse the list.
Key Concepts:

Structs in C.
Dynamic memory allocation.
Pointers and linked list traversal.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void createLinkedList(Node** node, int val) {
    *node = (Node*) malloc(sizeof(Node));
    (*node)->value = val;
    (*node)->next = NULL;
}

void insertEnd(Node** node, int val) {
    if (*node == NULL) {
        createLinkedList(node, val);
        return;
    }
    Node* t_ptr = *node;
    while (t_ptr->next != NULL) {
        t_ptr = t_ptr->next;
    }
    createLinkedList(&(t_ptr->next), val);
}

void insertBegin(Node** node, int val) {
    if (*node == NULL) {
        createLinkedList(node, val);
        return;
    }

    Node* t_ptr = NULL;
    createLinkedList(&t_ptr, val);
    t_ptr->next = *node;
    *node = t_ptr;
}

void removeNode(Node** node, int val) {
    if ((*node)->value == val) {
        Node* temp = *node;
        *node = (*node)->next;
        free(temp);
        return;
    }
    Node* t_ptr = (*node)->next;
    Node* prev = *node;
    while(t_ptr != NULL) {
        if (t_ptr->value == val) {
            if (prev != NULL) {
                prev->next = t_ptr->next;
            }
            free(t_ptr);
            return;
        }
        prev = t_ptr;
        t_ptr = t_ptr->next;
    }
}

void reverse(Node** node) {
    Node* prev = NULL;
    Node* curr = *node;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *node = (prev == NULL) ? *node : prev;
}

void print(Node* node) {
    Node* t_ptr = node;
    while (t_ptr != NULL) {
        printf("%d ", t_ptr->value);
        t_ptr = t_ptr->next;
    }
    printf("\n");
}

void freeLinkedList(Node** node) {
    Node* t_ptr = *node;
    while(t_ptr != NULL) {
        Node* temp = t_ptr;
        t_ptr = t_ptr->next;
        free(temp);
    }
    *node = NULL;
}

int main() {
    Node* node = NULL;
    createLinkedList(&node, 1);
    insertEnd(&node, 2);
    insertBegin(&node, 0);
    insertEnd(&node, 3);

    print(node);

    reverse(&node);

    print(node);

    removeNode(&node, 2);

    print(node);

    freeLinkedList(&node);

    return 0;
}