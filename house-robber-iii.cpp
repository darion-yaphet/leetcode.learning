//
// Created by user on 2024/10/22.
//

// https://leetcode.cn/problems/house-robber-iii/description/

#include "TreeNode.h"
#include <algorithm>

class Solution {
public:
    int rob(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        // 偷父节点
        int val1 = root->val;
        if (root->left) {
            val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left，相当于不考虑左孩子了

        }

        if (root->right) {
            val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right，相当于不考虑右孩子了
        }

        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        return std::max(val1, val2);
    }
};