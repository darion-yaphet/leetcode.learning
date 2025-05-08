//
// Created by darion.yaphet on 2025/5/8.
//

#include "TreeNode.h"

#include <queue>

using namespace std;

// https://leetcode.cn/problems/maximum-width-of-binary-tree
class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        // 队列存储 {节点, 编号}
        queue<pair<TreeNode *, unsigned long long> > q;
        q.push({root, 1}); // 根节点编号为 1

        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long left = 0, right = 0;

            for (int i = 0; i < levelSize; ++i) {
                auto [node, id] = q.front();
                q.pop();

                if (i == 0) {
                    left = id;
                }

                if (i == levelSize - 1) {
                    right = id;
                }

                // 将子节点加入队列，编号规则：左子节点 2 * id，右子节点 2 * id + 1
                if (node->left) {
                    q.push({node->left, 2 * id});
                }

                if (node->right) {
                    q.push({node->right, 2 * id + 1});
                }
            }

            // 计算当前层的宽度
            maxWidth = max(maxWidth, (int) (right - left + 1));
        }

        return maxWidth;
    }
};
