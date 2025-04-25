//
// Created by darion.yaphet on 2025/4/25.
//

#include "TreeNode.h"

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution {
public:
    /**
     * 二叉搜索树的特性：左子树的所有节点值小于根节点值，右子树的所有节点值大于根节点值。
     *
     * 如果 p 和 q 的值都小于 x->val，说明 p 和 q 都在 x 的左子树中。
     * 如果 p 和 q 的值都大于 x->val，说明 p 和 q 都在 x 的右子树中。
     * 如果 p 和 q 分别位于 x 的两侧（或其中之一等于 x），则 x 就是它们的最近公共祖先。
     *
     * 解题思路：
     * 从根节点开始遍历。
     * 如果当前节点的值大于 p 和 q 的值，则递归地在左子树中寻找 LCA。
     * 如果当前节点的值小于 p 和 q 的值，则递归地在右子树中寻找 LCA。
     * 否则，当前节点就是 p 和 q 的最近公共祖先。
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return nullptr;
        }

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};
