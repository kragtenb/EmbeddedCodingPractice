#include <iostream>
#include <memory>

class Node {
public:
    Node(int val, Node* left, Node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    int val;
    Node* left;
    Node* right;
};

class BinarySearchTree {
public:
    BinarySearchTree(int val) {
        head = std::make_unique<Node>(new Node(val, nullptr, nullptr));
    }

    void insert(int) {
        std::
    }

    void print() {

    }

private:
    std::unique_ptr<Node> head;
};