"""
You are given a binary tree. Write a function in C++ or Python 
to check if the tree is height-balanced. A binary tree is 
height-balanced if, for every node in the tree, the height 
difference between the left and right subtrees is at most 1.

Input: [3, 9, 20, null, null, 15, 7]
Output: True

Input: [1, 2, 2, 3, 3, null, null, 4, 4]
Output: False
"""

import pytest

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
def find_depth(root: TreeNode, depth: int):
    if (root is None):
        return (True, depth)
    left = find_depth(root.left, depth+1)
    right = find_depth(root.right, depth+1)
    max_depth = max(left[1], right[1])
    if (not left[0] or not right[0]):
        return (False, max_depth)
    return (True, max_depth) if abs(left[1] - right[1]) <= 1 else (False, max_depth)

def is_balanced(root: TreeNode) -> bool:
    return find_depth(root, 0)[0]

def test_is_balanced():
    node = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    assert is_balanced(node) is True
    
    node2 = TreeNode(1, TreeNode(2, TreeNode(3, TreeNode(4), TreeNode(4)), TreeNode(3)), TreeNode(2))
    assert is_balanced(node2) is False