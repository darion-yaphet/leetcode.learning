//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/symmetric-tree/description/

#include "TreeNode.h"
#include <queue>

class Solution {
public:
    bool helper(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }

        if (left == nullptr || right == nullptr) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }

        return helper(left->left, right->right) && helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        return helper(root, root);
    }

    bool isSymmetric2(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        std::queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode *leftNode = que.front();
            que.pop();

            TreeNode *rightNode = que.front();
            que.pop();

            if (!leftNode && !rightNode) {
                continue;
            }

            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }

            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }

        return true;
    }
};
