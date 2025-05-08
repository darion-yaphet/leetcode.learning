//
// Created by darion.yaphet on 2025/5/8.
//

#include "TreeNode.h"

#include <queue>

using namespace std;

// https://leetcode.cn/problems/deepest-leaves-sum/
class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);

        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            result = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }

                result += node->val;
            }
        }
        return result;
    }
};
