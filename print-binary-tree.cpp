//
// Created by darion.yaphet on 2025/5/3.
//

#include "TreeNode.h"
#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/print-binary-tree/
class Solution {
public:
    vector<vector<string> > printTree(TreeNode *root) {
        // 计算树的高度
        int height = getHeight(root);
        int m = height + 1; // 矩阵行数
        int n = (1 << (height + 1)) - 1; // 矩阵列数（2^(height+1) - 1）

        // 初始化矩阵，所有单元格填充为空字符串 ""
        vector<vector<string> > res(m, vector<string>(n, ""));

        // 递归放置节点
        placeNode(root, res, 0, (n - 1) / 2, height);
        return res;
    }

private:
    // 计算树的高度
    int getHeight(TreeNode *node) {
        // 空节点高度为 -1
        if (node == nullptr) {
            return -1;
        }

        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // 递归放置节点
    void placeNode(TreeNode *node, vector<vector<string> > &res, int r, int c, int height) {
        // 空节点直接返回
        if (node == nullptr) {
            return;
        }

        // 将当前节点的值放入矩阵
        res[r][c] = to_string(node->val);

        // 计算左右子节点的位置并递归放置
        if (node->left) {
            placeNode(node->left, res, r + 1, c - (1 << (height - r - 1)), height);
        }

        if (node->right) {
            placeNode(node->right, res, r + 1, c + (1 << (height - r - 1)), height);
        }
    }
};

// 测试代码
int main() {
    // 构造示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    // 调用函数生成格式化布局矩阵
    Solution solution;
    vector<vector<string>> res = solution.printTree(root);

    // 打印结果
    for (const auto& row : res) {
        for (const auto& cell : row) {
            cout << (cell.empty() ? " " : cell) << "\t";
        }
        cout << endl;
    }

    return 0;
}