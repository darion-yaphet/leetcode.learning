//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/

#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }

        vector<int> result;
        while (!queue.empty()) {
            int size = queue.size();
            int max = INT32_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();

                if (node->val > max) {
                    max = node->val;
                }

                if (node->left != nullptr) {
                    queue.emplace(node->left);
                }

                if (node->right != nullptr) {
                    queue.emplace(node->right);
                }
            }
            result.push_back(max);
        }

        return result;
    }
};