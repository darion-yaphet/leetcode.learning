//
// Created by Chenguang Wang on 2024/2/9.
//

//https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/

#include "Node.h"

class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> result;
        postorderInternal(root, result);
        return result;
    }

    void postorderInternal(Node *root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }

        for (auto &n: root->children) {
            postorderInternal(n, result);
        }

        result.push_back(root->val);
    }
};