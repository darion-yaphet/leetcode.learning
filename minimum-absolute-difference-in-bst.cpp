//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/

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
        vec.emplace_back(root->val);
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        traversal(root);

        if (vec.size() < 2) return 0;
        int result = INT_MAX;

        for (int index = 1; index < vec.size(); index++) {
            result = min(result, vec[index] - vec[index - 1]);
        }

        return result;
    }
};