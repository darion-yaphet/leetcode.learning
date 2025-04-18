//
// Created by Chenguang Wang on 2024/2/9.
//

#include "TreeNode.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr || root->left == nullptr || root->right == nullptr) {
            return 0;
        }

        int left = sumOfLeftLeaves(root->left);
        if (root->left != nullptr && (root->left->left == nullptr && root->left->right == nullptr)) {
            left = root->left->val;
        }

        return left + sumOfLeftLeaves(root->right);
    }
};