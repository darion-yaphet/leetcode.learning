//
// Created by Chenguang Wang on 2024/2/7.
//

// https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/

#include "TreeNode.h"
#include <algorithm>

class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = std::max(maxGain(node->left), 0);
        int rightGain = std::max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = std::max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + std::max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode *root) {
        maxGain(root);
        return maxSum;
    }
};
