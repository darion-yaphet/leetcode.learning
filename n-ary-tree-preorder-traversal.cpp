//
// Created by Chenguang Wang on 2024/2/9.
//

//https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description/

#include "Node.h"

class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> result;
        preorderInternal(root, result);
        return result;
    }

    void preorderInternal(Node *root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        result.push_back(root->val);
        for (auto &n: root->children) {
            preorderInternal(n, result);
        }
    }
};