//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/count-complete-tree-nodes/description/

#include "TreeNode.h"

class Solution {
public:
    int countNodes(TreeNode *root) {
        return traversal(root);
    }

    int traversal(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return traversal(root->left) + traversal(root->right) + 1;
    }
};