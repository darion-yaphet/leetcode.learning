//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/validate-binary-search-tree/description/

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


    bool isValidBST(TreeNode *root) {
        traversal(root);

        for (int i = 1; i < vec.size(); i++) {
            if (vec[i - 1] >= vec[i]) {
                return false;
            }
        }

        return true;
    }
};