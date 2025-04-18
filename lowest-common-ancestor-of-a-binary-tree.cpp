//
// Created by Chenguang Wang on 2024/2/9.
//

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include "TreeNode.h"

class Solution {
public:
    TreeNode *ans;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return false;
        }

        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        if ((lson && rson) ||
            ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }

        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};
