//
// Created by darion.yaphet on 2025/4/16.
//

// https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/

#include <iostream>
#include <unordered_set>
#include "TreeNode.h"

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        std::unordered_set<int> seen; // 用于存储已经访问过的节点值
        return dfs(root, k, seen);
    }

private:
    bool dfs(TreeNode *node, int k, std::unordered_set<int> &seen) {
        // 如果节点为空，返回 false
        if (node == nullptr) {
            return false;
        }

        // 检查是否存在另一个数使得两数之和等于 k
        if (seen.count(k - node->val)) {
            return true; // 找到满足条件的两个数
        }

        // 将当前节点值加入集合
        seen.insert(node->val);

        // 递归遍历左右子树
        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};

// 测试代码
int main() {
    // 构造测试用例二叉搜索树
    //       5
    //      / \
    //     3   6
    //    / \    \
    //   2   4    7
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    root->right = new TreeNode(6, nullptr, new TreeNode(7));

    Solution solution;

    // 测试用例
    int target1 = 9; // true (3 + 6)
    int target2 = 28; // false
    int target3 = 4; // true (2 + 2)

    std::cout << std::boolalpha; // 输出布尔值为 true/false
    std::cout << "Test 1: " << solution.findTarget(root, target1) << std::endl;
    std::cout << "Test 2: " << solution.findTarget(root, target2) << std::endl;
    std::cout << "Test 3: " << solution.findTarget(root, target3) << std::endl;

    return 0;
}
