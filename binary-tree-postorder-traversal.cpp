//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/binary-tree-postorder-traversal/description/

#include <vector>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

    void traversal(TreeNode *root, vector<int> &v) {
        if (root == nullptr) {
            return;
        }

        traversal(root->left, v);
        traversal(root->right, v);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack;
        if (root != nullptr) {
            stack.push(root);
        }

        while (!stack.empty()) {
            TreeNode *node = stack.top();
            if (node != nullptr) {
                stack.pop();
                stack.push(node); // 中
                stack.push(nullptr);

                if (node->right) {
                    stack.push(node->right); // 右
                }

                if (node->left) {
                    stack.push(node->left); // 左
                }

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