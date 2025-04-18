//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/average-of-levels-in-binary-tree/

#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }

        vector<double> result;
        while (!queue.empty()) {
            int size = queue.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();

                sum += node->val;

                if (node->left != nullptr) {
                    queue.emplace(node->left);
                }

                if (node->right != nullptr) {
                    queue.emplace(node->right);
                }
            }
            result.emplace_back(sum / size);
        }

        return result;
    }
};