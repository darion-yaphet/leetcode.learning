//
// Created by darion.yaphet on 2025/5/3.
//

#include "TreeNode.h"

using namespace std;

// https://leetcode.cn/problems/cousins-in-binary-tree/
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        // 记录 x 和 y 的深度和父节点
        int depthX = -1, depthY = -1;
        TreeNode *parentX = nullptr, *parentY = nullptr;

        // 辅助函数：递归遍历树
        dfs(root, nullptr, 0, x, y, depthX, depthY, parentX, parentY);

        // 检查是否是堂兄弟节点
        return (depthX == depthY) && (parentX != parentY);
    }

private:
    void dfs(TreeNode *node, TreeNode *parent, int depth, int x, int y,
             int &depthX, int &depthY, TreeNode *&parentX, TreeNode *&parentY) {
        if (node == nullptr) {
            return;
        }

        // 如果找到了 x 或 y，记录其深度和父节点
        if (node->val == x) {
            depthX = depth;
            parentX = parent;
        }

        if (node->val == y) {
            depthY = depth;
            parentY = parent;
        }

        // 如果已经找到 x 和 y，则提前终止递归
        if (depthX != -1 && depthY != -1) {
            return
        }

        // 递归遍历左子树和右子树
        dfs(node->left, node, depth + 1, x, y, depthX, depthY, parentX, parentY);
        dfs(node->right, node, depth + 1, x, y, depthX, depthY, parentX, parentY);
    }
};
