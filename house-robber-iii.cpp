//
// Created by user on 2024/10/22.
//

// https://leetcode.cn/problems/house-robber-iii/description/

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    int rob(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        // 偷父节点
        int val1 = root->val;
        if (root->left) {
            val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left，相当于不考虑左孩子了
        }

        if (root->right) {
            val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right，相当于不考虑右孩子了
        }

        // 不偷父节点
        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
        return std::max(val1, val2);
    }

    /**
     * 如果选择当前节点，则不能选择其子节点：
     * rob=node.val+sum of not_rob(child nodes)
     *
     * 如果不选择当前节点，则可以选择或不选择其子节点：
     * not_rob=sum of max(rob(child),not_rob(child))
     */
    int rob2(TreeNode *root) {
        std::vector<int> result = dp(root);
        return max(result[0], result[1]); // 返回选择或不选择根节点的最大值
    }

    // 辅助函数：返回 [rob, not_rob]
    vector<int> dp(TreeNode *node) {
        // 空节点返回 [0, 0]
        if (!node) {
            return {0, 0};
        }

        // 递归计算左右子树的结果
        vector<int> left = dp(node->left);
        vector<int> right = dp(node->right);

        // 选择当前节点时的最大金额
        int rob = node->val + left[1] + right[1];

        // 不选择当前节点时的最大金额
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);

        return {rob, not_rob};
    }
};
