//
// Created by Chenguang Wang on 2024/2/21.
//

//https://leetcode.cn/problems/path-sum-ii/description/

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        backtracking(path, root, 0, targetSum);
        return result;
    }

    void backtracking(vector<int> &path, TreeNode *root, int sum, int targetSum) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);
        sum += root->val;

        if (targetSum == sum && root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
        }

        backtracking(path, root->left, sum, targetSum);
        backtracking(path, root->right, sum, targetSum);
        path.pop_back();
    }
};