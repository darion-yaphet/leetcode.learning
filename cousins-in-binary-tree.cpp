//
// Created by darion.yaphet on 2025/5/8.
//

#include "TreeNode.h"

#include <queue>

using namespace std;

// https://leetcode.cn/problems/cousins-in-binary-tree/description/
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (root == nullptr) {
            return false;
        }

        queue<pair<TreeNode *, pair<TreeNode *, int> > > q;
        q.push({root, {nullptr, 0}});

        int depthX = -1, depthY = -1;
        TreeNode *parentX = nullptr, *parentY = nullptr;

        while (!q.empty()) {
            auto [node, info] = q.front();
            q.pop();

            TreeNode *parent = info.first;
            int depth = info.second;

            if (node->val == x) {
                depthX = depth;
                parentX = parent;
            }

            if (node->val == y) {
                depthY = depth;
                parentY = parent;
            }

            if (depthX != -1 && depthY != -1) {
                break;
            }

            if (node->left) {
                q.push({node->left, {node, depth + 1}});
            }
            if (node->right) {
                q.push({node->right, {node, depth + 1}});
            }
        }

        return depthX == depthY && parentX != parentY;
    }
};
