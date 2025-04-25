//
// Created by darion.yaphet on 2025/4/25.
//

#include "TreeNode.h"

class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        int result = pathSumFromNode(root, targetSum);

        result += pathSum(root->left, targetSum);
        result += pathSum(root->right, targetSum);
        return result;
    }

private:
    int pathSumFromNode(TreeNode *node, long targetSum) {
        if (node == nullptr) {
            return 0;
        }

        int count = 0;
        if (node->val == targetSum) {
            // 当前节点的值等于目标值，路径数加 1
            count++;
        }

        // 递归计算左子树和右子树的路径数
        count += pathSumFromNode(node->left, targetSum - node->val);
        count += pathSumFromNode(node->right, targetSum - node->val);

        return count;
    }
};
