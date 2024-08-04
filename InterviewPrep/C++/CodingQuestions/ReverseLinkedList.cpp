/*
    Write a function in C++ to reverse a singly linked list. Explain your approach and 
    discuss the time and space complexity of your solution.
*/

#include <iostream>

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

Node* assignParent(Node* node, Node* parent) {
    Node* temp = node->next;
    node->next = parent;
    if (temp == nullptr) {
        return node;
    }
    return assignParent(temp, node);
}

Node* reverseLinkedList(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    return assignParent(node, nullptr);
}

int main() {
    Node* head = new Node(1);
    Node* temp = head;
    for (int i=2; i < 10; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    std::cout << "Original list: ";
    temp = head;
    while (temp) {
        std::cout << temp->val;
        temp = temp->next;
    }
    std::cout << std::endl;

    Node* reversed = reverseLinkedList(head);

    std::cout << "Reversed list: ";
    temp = reversed;
    while (temp) {
        std::cout << temp->val;
        temp = temp->next;
    }
    std::cout << std::endl;

    temp = reversed;
    while(temp) {
        Node* f = temp;
        temp = temp->next;
        delete f;
    }
    
    return 0;
}