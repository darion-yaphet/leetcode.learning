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
};