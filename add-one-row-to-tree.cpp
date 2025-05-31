//
// Created by darion.yaphet on 2025/5/28.
//

#include "TreeNode.h"
#include <queue>

using namespace std;

// https://leetcode.cn/problems/add-one-row-to-tree
class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        // 特殊情况：depth == 1，创建新的根节点
        // 原始树就是新根的左子树。
        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // BFS 层序遍历找到 depth - 1 层
        queue<TreeNode *> q;
        q.push(root);
        int currentDepth = 1;
        while (!q.empty() && currentDepth < depth - 1) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
            ++currentDepth;
        }

        // 此时队列中是 depth-1 层的所有非空节点
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            // 创建新节点作为新的左、右子节点
            TreeNode *newLeft = new TreeNode(val);
            TreeNode *newRight = new TreeNode(val);

            // 原来的左右子树接在新节点下
            // 原来的左子树应该是新的左子树根的左子树。
            // 原来的右子树应该是新的右子树根的右子树。
            newLeft->left = node->left;
            newRight->right = node->right;

            // 插入新节点到当前节点的左右
            node->left = newLeft;
            node->right = newRight;
        }

        return root;
    }
};
