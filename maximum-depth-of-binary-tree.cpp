//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/maximum-depth-of-binary-tree/

#include "TreeNode.h"

#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth2(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            level += 1;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return level;
    }
};