//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/

#include "TreeNode.h"
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> vec;

    void traversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        traversal(root);

        if (vec.size() < k) {
            return -1;
        }

        return vec[k];
    }
};