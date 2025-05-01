//
// Created by darion.yaphet on 2025/5/1.
//

#include <algorithm>
#include <climits>

#include "TreeNode.h"

// https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree/
class Solution {
public:
    int findSecondMinimumValue(TreeNode *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return -1;
        }

        // 根节点的值是最小值
        int minVal = root->val;
        long secondMin = findSecondMin(root, minVal);
        return secondMin == LONG_MAX ? -1 : secondMin;
    }

    long findSecondMin(TreeNode *node, int minVal) {
        // 空节点返回最大值
        if (node == nullptr) {
            return LONG_MAX;
        }

        // 如果当前节点值大于最小值，直接返回当前值（潜在的第二小值）
        // 左右子树节点没有比这个值更小的
        if (node->val > minVal) {
            return node->val;
        }

        // 递归查找左右子树的第二小值
        long leftSecondMin = findSecondMin(node->left, minVal);
        long rightSecondMin = findSecondMin(node->right, minVal);

        // 返回左右子树中较小的第二小值
        return std::min(leftSecondMin, rightSecondMin);
    }
};
