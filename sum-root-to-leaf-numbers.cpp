//
// Created by Chenguang Wang on 2024/1/22.
//

// https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/

#include "TreeNode.h"

class Solution {
public:
    int dfs(TreeNode *root, int prev) {
        if (root == nullptr) {
            return 0;
        }

        int sum = prev * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }

    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
};