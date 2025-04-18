//
// Created by Chenguang Wang on 2024/1/22.
//

// https://leetcode.cn/problems/path-sum/description/

#include "TreeNode.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};