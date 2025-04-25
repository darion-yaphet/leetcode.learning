//
// Created by darion.yaphet on 2025/4/25.
//

#include "TreeNode.h"

// https://leetcode.cn/problems/merge-two-binary-trees/
class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) {
            return root2;
        }

        if (root2 == nullptr) {
            return root1;
        }

        TreeNode *merged = new TreeNode(root1->val + root2->val);
        merged->left = mergeTrees(root1->left, root2->left);
        merged->right = mergeTrees(root1->right, root2->right);
        return merged;
    }
};
