//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/

#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }

        int level = 0;
        vector<vector<int>> result;
        while (!queue.empty()) {
            level += 1;
            int size = queue.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop();

                v.emplace_back(node->val);

                if (node->left != nullptr) {
                    queue.emplace(node->left);
                }

                if (node->right != nullptr) {
                    queue.emplace(node->right);
                }
            }

            if (level % 2 == 0) {
                reverse(v.begin(), v.end());
            }
            result.emplace_back(std::move(v));
        }

        return result;
    }
};
