//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/invert-binary-tree/

#include "TreeNode.h"
#include <algorithm>

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }

        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};