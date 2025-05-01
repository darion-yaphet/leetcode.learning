//
// Created by darion.yaphet on 2025/5/1.
//

#include "TreeNode.h"

// https://leetcode.cn/problems/search-in-a-binary-search-tree/
class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }

        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
