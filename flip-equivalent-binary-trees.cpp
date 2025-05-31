//
// Created by darion.yaphet on 2025/5/29.
//

#include "TreeNode.h"

// https://leetcode.cn/problems/flip-equivalent-binary-trees
class Solution {
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) {
            return true;
        }

        if (!root1 || !root2 || root1->val != root2->val) {
            return false;
        }

        // Check both possible configurations
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
