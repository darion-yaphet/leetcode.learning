//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/

#include "TreeNode.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> vec;

    void traversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traversal(root->left);
        vec.emplace_back(root->val);
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        traversal(root);

        if (vec.size() < 2) {
            return 0;
        }

        int result = INT_MAX;

        for (int index = 1; index < vec.size(); index++) {
            result = min(result, vec[index] - vec[index - 1]);
        }

        return result;
    }

    int getMinimumDifference2(TreeNode *root) {
        int minDiff = numeric_limits<int>::max(); // 初始化最小差值为最大值
        int prev = -1; // 记录前一个节点的值，初始为 -1 表示未访问过

        stack<TreeNode *> s;
        TreeNode *curr = root;

        // 迭代中序遍历
        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            // 计算当前节点与前一个节点的差值
            if (prev != -1) {
                // 跳过第一个节点
                minDiff = min(minDiff, curr->val - prev);
            }

            prev = curr->val; // 更新前一个节点的值
            curr = curr->right;
        }
        return minDiff;
    }
};
