//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/binary-tree-preorder-traversal/description/

#include <vector>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal(TreeNode *root, vector<int> &v) {
        if (root == nullptr) {
            return;
        }

        v.push_back(root->val);
        traversal(root->left, v);
        traversal(root->right, v);
    }

    vector<int> preorderTraversal2(TreeNode *root) {
        vector<int> result;
        std::stack<TreeNode *> stack;
        if (root != nullptr) {
            stack.push(root);
        }

        while (!stack.empty()) {
            TreeNode *node = stack.top();
            if (node != nullptr) {
                stack.pop();
                if (node->right) {
                    stack.push(node->right);  // 右
                }

                if (node->left) {
                    stack.push(node->left);    // 左
                }

                stack.push(node); // 中
                stack.push(nullptr);
            } else {
                stack.pop();
                node = stack.top();
                stack.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};