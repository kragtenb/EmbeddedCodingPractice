/*
You are given a binary tree. Write a function in C++ or Python 
to check if the tree is height-balanced. A binary tree is 
height-balanced if, for every node in the tree, the height 
difference between the left and right subtrees is at most 1.

Input: [3, 9, 20, null, null, 15, 7]
Output: True

Input: [1, 2, 2, 3, 3, null, null, 4, 4]
Output: False
*/

#include <cassert>
#include <algorithm>
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* left=nullptr, TreeNode* right=nullptr) : val(val), left(left), right(right) {}
};

bool findDepth(TreeNode* root, int& depth) {
    if (root == nullptr) {
        return true;
    }
    depth++;
    int leftDepth = depth;
    int rightDepth = depth;
    if (!findDepth(root->left, leftDepth) || !findDepth(root->right, rightDepth)) {
        return false;
    }
    depth = std::max(leftDepth, rightDepth);
    return std::abs(leftDepth-rightDepth) <= 1;
}

bool isBalanced(TreeNode* root) {
    int depth = 0;
    return findDepth(root, depth);
}

int main() {
    // Test tree 1: Balanced
    TreeNode* tree1 = new TreeNode(3);
    tree1->left = new TreeNode(9);
    tree1->right = new TreeNode(20);
    tree1->right->left = new TreeNode(15);
    tree1->right->right = new TreeNode(7);
    assert(isBalanced(tree1) == true);

    // Test tree 2: Not Balanced
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(2);
    tree2->left->left = new TreeNode(3);
    tree2->left->right = new TreeNode(3);
    tree2->left->left->left = new TreeNode(4);
    tree2->left->left->right = new TreeNode(4);
    assert(isBalanced(tree2) == false);

    std::cout << "All tests passed!" << std::endl;

    // Clean up memory
    delete tree1->right->right;
    delete tree1->right->left;
    delete tree1->right;
    delete tree1->left;
    delete tree1;

    delete tree2->left->left->right;
    delete tree2->left->left->left;
    delete tree2->left->right;
    delete tree2->left->left;
    delete tree2->right;
    delete tree2->left;
    delete tree2;

    return 0;
}