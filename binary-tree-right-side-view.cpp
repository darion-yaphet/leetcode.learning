//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/binary-tree-right-side-view/description/

#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }

        vector<int> result;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();

                if (i == size - 1) {
                    result.emplace_back(node->val);
                }

                if (node->left != nullptr) {
                    queue.emplace(node->left);
                }

                if (node->right != nullptr) {
                    queue.emplace(node->right);
                }
            }
        }

        return result;
    }
};