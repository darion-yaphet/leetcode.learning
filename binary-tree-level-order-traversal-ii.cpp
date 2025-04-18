//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/

#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }

        vector<vector<int>> result;
        while (!queue.empty()) {
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
            result.emplace_back(std::move(v));
        }

        reverse(result.begin(), result.end());
        return result;
    }
};