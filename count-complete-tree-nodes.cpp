//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/count-complete-tree-nodes/description/

#include "TreeNode.h"

class Solution {
public:
    int countNodes(TreeNode *root) {
        return traversal(root);
    }

    int traversal(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return traversal(root->left) + traversal(root->right) + 1;
    }

    /**
     * 完全二叉树的高度可以通过从根节点一直向左子树遍历得到。
     * 如果左子树和右子树的高度相同，则左子树是一棵满二叉树，可以直接计算节点数。
     * 如果左子树和右子树的高度不同，则右子树是一棵满二叉树，可以直接计算节点数。
     */
    int countNodes2(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        // 计算左子树和右子树的高度
        int leftHeight = getLeftHeight(root->left);
        int rightHeight = getLeftHeight(root->right);

        if (leftHeight == rightHeight) {
            // 左子树是满二叉树
            return (1 << leftHeight) + countNodes(root->right); // 2^leftHeight - 1 + 根节点 + 右子树节点数
        } else {
            // 右子树是满二叉树
            return (1 << rightHeight) + countNodes(root->left); // 2^rightHeight - 1 + 根节点 + 左子树节点数
        }
    }

private:
    // 获取完全二叉树左侧的高度
    int getLeftHeight(TreeNode *node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
};
