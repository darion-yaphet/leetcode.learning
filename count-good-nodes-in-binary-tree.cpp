//
// Created by darion.yaphet on 2025/5/8.
//

#include "TreeNode.h"

using namespace std;

// https://leetcode.cn/problems/count-good-nodes-in-binary-tree/description/
class Solution {
public:
    int goodNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int result = 0;
        dfs(root, root->val, result);
        return result;
    }

    void dfs(TreeNode *node, int max, int &result) {
        if (node == nullptr) {
            return;
        }

        if (node->val >= max) {
            max = node->val;
            result++;
        }

        dfs(node->left, max, result);
        dfs(node->right, max, result);
    }
};
