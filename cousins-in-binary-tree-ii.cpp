//
// Created by Chenguang Wang on 2024/2/7.
//

// https://leetcode.cn/problems/cousins-in-binary-tree-ii/description/

#include <vector>
#include "TreeNode.h"

class Solution {
public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        std::vector<TreeNode *> queue;
        queue.push_back(root);
        root->val = 0;

        while (!queue.empty()) {
            std::vector<TreeNode *> q;
            int sum = 0;
            for (const auto &e: queue) {
                if (e->left != nullptr) {
                    q.push_back(e->left);
                    sum += e->left->val;
                }

                if (e->right != nullptr) {
                    q.push_back(e->right);
                    sum += e->right->val;
                }
            }

            for (const auto &e: queue) {
                int child_sum = 0;
                child_sum += e->left != nullptr ? e->left->val : 0;
                child_sum += e->right != nullptr ? e->right->val : 0;

                if (e->left) {
                    e->left->val = sum - child_sum;
                }

                if (e->right) {
                    e->right->val = sum - child_sum;
                }
            }
            queue = q;
        }
        return root;
    }
};