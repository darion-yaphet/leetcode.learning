//
// Created by darion.yaphet on 2025/5/3.
//

#include "TreeNode.h"

// https://leetcode.cn/problems/univalued-binary-tree/
class Solution {
public:
    bool isUnivalTree(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        if (root->left != nullptr && root->left->val != root->val) {
            return false;
        }

        if (root->right != nullptr && root->right->val != root->val) {
            return false;
        }

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }

    bool isUnivalTree2(TreeNode *root) {
        if (!root) return true; // 空树是单值二叉树
        return dfs(root, root->val);
    }

    // 辅助函数：递归检查每个节点的值是否与基准值相等
    bool dfs(TreeNode *node, int value) {
        // 空节点默认满足条件
        if (node == nullptr) {
            return true;
        }

        // 当前节点值不等于基准值
        if (node->val != value) {
            return false;
        }

        return dfs(node->left, value) && dfs(node->right, value); // 检查左右子树
    }
};
