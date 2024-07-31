#include <iostream>
#include <memory>

struct Node {
    int val;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree(int val) {
        head = std::make_unique<Node>(val);
    }

    void insert(int val) {
        head = insertInOrder(std::move(head), val);
    }

    void print() {
        printInOrder(head.get());
        std::cout << std::endl;
    }

private:
    std::unique_ptr<Node> head;

    std::unique_ptr<Node> insertInOrder(std::unique_ptr<Node> node, int val) {
        if (node == nullptr) {
            return std::make_unique<Node>(val);
        }

        if (val < node->val) {
            node->left = insertInOrder(std::move(node->left), val);
        } else if (val > node->val) {
            node->right = insertInOrder(std::move(node->right), val);
        }

        return node;
    }

    void printInOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        printInOrder(node->left.get());
        std::cout << node->val << " ";
        printInOrder(node->right.get());
    }
};

int main() {
    BinarySearchTree bst(20);

    bst.insert(5);
    bst.insert(4);
    bst.insert(25);
    bst.insert(40);
    bst.insert(8);
    bst.insert(7);

    bst.print();
    bst.print();
    
    return 0;
}