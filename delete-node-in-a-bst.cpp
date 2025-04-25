//
// Created by darion.yaphet on 2025/4/25.
//

#include "TreeNode.h"

class Solution {
public:
    /**
     * 左子树的所有节点值小于根节点值，右子树的所有节点值大于根节点值。
     *
     * 要删除的节点是叶子节点 ：直接删除该节点即可。
     *
     * 要删除的节点只有一个子节点 ：将该节点替换为其唯一的子节点。
     *
     * 要删除的节点有两个子节点 ：
     *  找到其右子树中的最小值节点（或左子树中的最大值节点）。
     *  用该最小值节点的值替换当前节点的值。
     *  然后递归地删除这个最小值节点（它最多有一个子节点，因此可以归结为前两种情况）。
     */
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->val) {
            // 在左子树中查找
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // 在右子树中查找
            root->right = deleteNode(root->right, key);
        } else {
            // 找到了要删除的节点
            if (!root->left && !root->right) {
                // 情况 1：叶子节点
                delete root; // 释放内存
                return nullptr;
            } else if (!root->left) {
                // 情况 2：只有右子树
                TreeNode *temp = root->right;
                delete root; // 释放内存
                return temp;
            } else if (!root->right) {
                // 情况 2：只有左子树
                TreeNode *temp = root->left;
                delete root; // 释放内存
                return temp;
            } else {
                // 情况 3：有两个子节点
                // 找到右子树中的最小值节点
                TreeNode *minNode = findMin(root->right);
                root->val = minNode->val; // 替换当前节点的值
                root->right = deleteNode(root->right, minNode->val); // 删除最小值节点
            }
        }
        return root;
    }

private:
    // 找到右子树中的最小值节点
    TreeNode *findMin(TreeNode *node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
