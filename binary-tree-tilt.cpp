//
// Created by darion.yaphet on 2025/8/13.
//

#include "TreeNode.h"
#include <cmath>

class Solution {
    int totalTilt; // 存储整个树的坡度总和

    // 后序遍历函数：返回以当前节点为根的子树的节点值之和
    // 同时计算并累加每个节点的坡度
    int postorder(TreeNode *node) {
        // 空节点的情况
        if (node == nullptr) {
            return 0;
        }

        // 递归计算左子树的节点值之和
        int leftSum = postorder(node->left);

        // 递归计算右子树的节点值之和
        int rightSum = postorder(node->right);

        // 计算当前节点的坡度：左子树和与右子树和的差的绝对值
        int nodeTilt = std::abs(leftSum - rightSum);

        // 将当前节点的坡度累加到总坡度中
        totalTilt += nodeTilt;

        // 返回以当前节点为根的子树的节点值之和
        // 包括当前节点值、左子树和、右子树和
        return node->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode *root) {
        totalTilt = 0; // 初始化总坡度
        postorder(root); // 执行后序遍历
        return totalTilt;
    }
};
