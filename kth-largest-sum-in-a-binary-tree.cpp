//
// Created by darion.yaphet on 2025/5/5.
//

#include "TreeNode.h"

#include <queue>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/
class Solution {
public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root);

        vector<long long> sums;

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();

                sum += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            sums.push_back(sum);
        }

        sort(sums.begin(), sums.end(), greater<>());
        return sums.size() >= k ? sums[k - 1] : -1;
    }
};
