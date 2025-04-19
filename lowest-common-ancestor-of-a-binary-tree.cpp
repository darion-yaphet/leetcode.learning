//
// Created by Chenguang Wang on 2024/2/9.
//

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include "TreeNode.h"

/**
 * 如果 p 和 q 分别位于当前节点的左右子树中，则当前节点就是它们的最近公共祖先。
 * 如果 p 和 q 都位于左子树或右子树中，则递归地在相应的子树中寻找最近公共祖先。
 *
 * 使用递归方法：
 * 如果当前节点为空，返回 nullptr。
 * 如果当前节点是 p 或 q，直接返回当前节点。
 * 递归地在左子树和右子树中寻找 p 和 q。
 * 如果左子树和右子树分别返回非空结果，则当前节点是最近公共祖先。
 * 如果只有一个子树返回非空结果，则返回该子树的结果。
 */
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

    // 主函数：找到两个节点的最近公共祖先
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 基本情况
        if (!root || root == p || root == q) {
            return root;
        }

        // 递归查找左子树和右子树
        TreeNode* left = lowestCommonAncestor2(root->left, p, q);
        TreeNode* right = lowestCommonAncestor2(root->right, p, q);

        // 如果左子树和右子树分别包含 p 和 q，则当前节点是最近公共祖先
        if (left && right) {
            return root;
        }

        // 否则返回非空的结果
        return left ? left : right;
    }
};
