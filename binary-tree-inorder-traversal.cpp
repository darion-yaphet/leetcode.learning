//
// Created by Chenguang Wang on 2024/2/8.
//

// https://leetcode.cn/problems/binary-tree-inorder-traversal/description/

#include <vector>
#include <stack>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal(TreeNode *root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        traversal(root->left, result);
        result.push_back(root->val);
        traversal(root->right, result);
    }

    vector<int> inorderTraversal2(TreeNode *root) {
        vector<int> result;
        std::stack<TreeNode *> stack;
        if (root != nullptr) {
            stack.push(root);
        }

        while (!stack.empty()) {
            TreeNode *node = stack.top();
            if (node != nullptr) {
                stack.pop(); // 将该节点弹出，避免᯿复操作，下⾯再将右中左节点添加到栈中
                if (node->right) {
                    stack.push(node->right); // 添加右节点（空节点不⼊栈）
                }

                stack.push(node); // 添加中节点
                stack.push(nullptr); // 中节点访问过，但是还没有处理，加⼊空节点做为标记。

                if (node->left) {
                    stack.push(node->left); // 添加左节点（空节点不⼊栈）
                }
            } else { // 只有遇到空节点的时候，才将下⼀个节点放进结果集
                stack.pop(); // 将空节点弹出
                node = stack.top(); // ᯿新取出栈中元素
                stack.pop();
                result.push_back(node->val); // 加⼊到结果集
            }
        }
        return result;
    }
};