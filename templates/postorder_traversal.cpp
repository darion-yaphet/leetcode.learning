//
// Created by darion.yaphet on 2024/7/26.
//

#include "TreeNode.h"

#include <iostream>
#include <vector>

// Recursive template for post-order traversal
void postorderTraversal(TreeNode *root, std::vector<int> &result) {
    // empty nodes return directly.
    if (root == nullptr) {
        return;
    }

    // Recursively traverses the left subtree.
    postorderTraversal(root->left, result);

    // Recursively traverses the right subtree.
    postorderTraversal(root->right, result);

    // Access root node.
    result.push_back(root->val);
}

std::vector<int> postorderTraversalHelper(TreeNode *root) {
    std::vector<int> result;
    postorderTraversal(root, result);
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

    std::vector<int> postorder = postorderTraversalHelper(root);

    for (int num: postorder) {
        std::cout << num << " ";
    }
    return 0;
}