//
// Created by Chenguang Wang on 2024/2/23.
//

// https://leetcode.cn/problems/trim-a-binary-search-tree

#include "TreeNode.h"

class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val < low) {
            return trimBST(root->right, low, high);
        }

        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

    TreeNode *trimBST2(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }

        // 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) {
                // 小于L往右走
                root = root->right;
            } else {
                // 大于R往左走
                root = root->left;
            }

            TreeNode *cur = root;
            // 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
            while (cur != nullptr) {
                while (cur->left && cur->left->val < low) {
                    cur->left = cur->left->right;
                }
                cur = cur->left;
            }
            cur = root;

            // 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
            while (cur != nullptr) {
                while (cur->right && cur->right->val > high) {
                    cur->right = cur->right->left;
                }
                cur = cur->right;
            }
            return root;
        }

    }
};