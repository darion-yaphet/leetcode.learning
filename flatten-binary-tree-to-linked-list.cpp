//
// Created by Chenguang Wang on 2024/1/24.
//

// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode *> v;

    void flatten(TreeNode *root) {
        preorderTraversal(root);
        int size = v.size();
        for (int i = 1; i < size; i++) {
            TreeNode *prev = v[i - 1];
            TreeNode *current = v[i];
            prev->left = nullptr;
            prev->right = current;
        }
    }

    void preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        v.push_back(root);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void flatten2(TreeNode *root) {
        TreeNode *curr = root;

        while (curr != nullptr) {
            // 如果当前节点有左子树
            if (curr->left != nullptr) {
                // 找到左子树的最右节点
                TreeNode *leftRightMost = curr->left;
                while (leftRightMost->right != nullptr) {
                    leftRightMost = leftRightMost->right;
                }

                // 将左子树移到右子树的位置
                leftRightMost->right = curr->right; // 连接原右子树
                curr->right = curr->left; // 左子树变为右子树
                curr->left = nullptr; // 左子树置空
            }

            // 移动到下一个节点
            curr = curr->right;
        }
    }
};
