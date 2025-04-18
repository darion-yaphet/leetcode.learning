//
// Created by Chenguang Wang on 2024/2/9.
//

// https://leetcode.cn/problems/balanced-binary-tree/description/

#include "TreeNode.h"
#include <algorithm>

class Solution {
public:

    int height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else {
            int l = height(root->left);
            int r = height(root->right);
            return std::max(l, r) + 1;
        }
    }

    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        int lh = height(root->left);
        int rh = height(root->right);
        return abs(lh - rh) <= 1 &&
               isBalanced(root->left) &&
               isBalanced(root->right);
    }
};