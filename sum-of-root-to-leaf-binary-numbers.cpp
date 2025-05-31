//
// Created by darion.yaphet on 2025/5/31.
//

#include "TreeNode.h"

// https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/
class Solution {
public:
    int sumRootToLeaf(TreeNode *root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode *node, int currentValue) {
        if (node == nullptr) {
            return 0;
        }

        currentValue = currentValue * 2 + node->val;

        if (node->left == nullptr && node->right == nullptr) {
            return currentValue;
        }

        return dfs(node->left, currentValue) + dfs(node->right, currentValue);
    }
};
