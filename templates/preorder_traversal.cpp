//
// Created by darion.yaphet on 2024/7/26.
//

#include "TreeNode.h"

#include <iostream>
#include <vector>

// Recursive template for preorder traversal.
void preorderTraversal(TreeNode *root, std::vector<int> &result) {
    // empty nodes return directly.
    if (root == nullptr) {
        return;
    }

    // Access root node.
    result.push_back(root->val);

    // Recursively traverses the left subtree.
    preorderTraversal(root->left, result);

    // Recursively traverses the right subtree.
    preorderTraversal(root->right, result);
}

std::vector<int> preorderTraversalHelper(TreeNode *root) {
    std::vector<int> result;
    preorderTraversal(root, result);
    return result;
}

int main() {
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> preorder = preorderTraversalHelper(root);

    for (int num: preorder) {
        std::cout << num << " ";
    }
    return 0;
}