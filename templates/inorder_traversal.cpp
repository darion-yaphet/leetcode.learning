//
// Created by darion.yaphet on 2024/7/26.
//

#include "TreeNode.h"

#include <iostream>
#include <vector>

// Recursive template for mid-order traversal.
void inorderTraversal(TreeNode *root, std::vector<int> &result) {
    // empty nodes return directly.
    if (root == nullptr) {
        return;
    }

    // Recursively traverses the left subtree.
    inorderTraversal(root->left, result);

    // Access root node.
    result.push_back(root->val);

    // Recursively traverses the right subtree.
    inorderTraversal(root->right, result);
}


std::vector<int> inorderTraversalHelper(TreeNode *root) {
    std::vector<int> result;
    inorderTraversal(root, result);
    return result;
}

int main() {
    //       4
    //      / \
    //     2   6
    //    / \ / \
    //   1  3 5  7
    auto *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    std::vector<int> inorder = inorderTraversalHelper(root);

    for (int num: inorder) {
        std::cout << num << " ";
    }
    return 0;
}