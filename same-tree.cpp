//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/same-tree/description/

#include "TreeNode.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};