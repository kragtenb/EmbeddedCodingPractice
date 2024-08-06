#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

Node* pushFront(Node* node, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = val;
    newNode->next = (node == NULL) ? NULL: node;
    return newNode;
}

Node* pushBack(Node* node, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = val;
    newNode->next = NULL;
    if (node == NULL) {
        return newNode;
    }
    Node* curr = node;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return node;
}

Node* deleteNode(Node* node, int val) {
    if (node == NULL) {
        return NULL;
    }
    Node* curr = node;
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->value == val) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        return node;
    }
    if (prev == NULL) {
        Node* new_head = curr->next;
        free(curr);
        return new_head;
    }
    prev->next = curr->next;
    free(curr);
    return node;
}

void printList(Node* node) {
    Node* temp = node;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* linkedList = NULL;
    linkedList = pushFront(linkedList, 5);
    linkedList = pushFront(linkedList, 2);
    linkedList = pushBack(linkedList, 7);

    printList(linkedList);

    linkedList = deleteNode(linkedList, 2);

    printList(linkedList);

    Node* temp = linkedList;
    while (temp != NULL) {
        Node* fTemp = temp;
        temp = temp->next;
        free(fTemp);
    }

    return 0;
}