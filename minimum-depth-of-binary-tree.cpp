//
// Created by Chenguang Wang on 2024/2/9.
//

// https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/

#include "TreeNode.h"
#include <algorithm>
#include <queue>

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right != nullptr) {
            return 1 + minDepth(root->right);
        }

        if (root->left != nullptr && root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }

    int minDepth2(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int depth = 0;
        std::queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            depth++; // 记录最⼩深度
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }

                if (!node->left && !node->right) { // 当左右孩⼦都为空的时候，说明是最低点的⼀层了，退出
                    return depth;
                }
            }
        }
        return depth;
    }
};