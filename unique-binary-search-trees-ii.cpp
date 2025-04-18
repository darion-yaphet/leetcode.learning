//
// Created by Chenguang Wang on 2024/2/9.
//

//https://leetcode.cn/problems/unique-binary-search-trees-ii/description/

#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
private:
public:
    vector<TreeNode *> generateTrees(int n) {
        return backtracking(1, n);
    }

    vector<TreeNode *> backtracking(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode *> allTrees;
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftTrees = backtracking(start, i - 1);
            vector<TreeNode *> rightTrees = backtracking(i + 1, end);

            for (auto &left: leftTrees) {
                for (auto &right: rightTrees) {
                    TreeNode *currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.push_back(currTree);
                }
            }
        }
        return allTrees;
    }
};