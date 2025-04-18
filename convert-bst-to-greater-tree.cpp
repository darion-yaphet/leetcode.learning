//
// Created by Chenguang Wang on 2024/2/23.
//

// https://leetcode.cn/problems/convert-bst-to-greater-tree/description/

#include "TreeNode.h"

class Solution {
private:
    int sum = 0;
public:
    TreeNode *convertBST(TreeNode *root) {
        return traversal(root);
    }

    TreeNode *traversal(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }

        traversal(root->right);

        sum += root->val;
        root->val = sum;

        traversal(root->left);
        return root;
    }
};