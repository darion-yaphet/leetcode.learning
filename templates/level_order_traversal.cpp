//
// Created by darion.yaphet on 2024/7/26.
//

#include "TreeNode.h"

#include <iostream>
#include <vector>
#include <queue>

// Hierarchical traversal of the template
void levelOrderTraversal(TreeNode *root) {
    // If the root node is empty, return it directly.
    if (!root) {
        return;
    }

    std::queue<TreeNode *> q;
    q.push(root); // Add the root node to the queue.

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        // Access the value of the current node.
        std::cout << current->val << " ";

        // If there is a left child node, add it to the queue.
        if (current->left) {
            q.push(current->left);
        }

        // If there is a right child node, add it to the queue.
        if (current->right) {
            q.push(current->right);
        }
    }
}

int main() {
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    levelOrderTraversal(root);
    return 0;
}