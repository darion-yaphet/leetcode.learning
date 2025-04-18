//
// Created by Chenguang Wang on 2024/2/14.
//

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int max = INT_MIN;
        int index = -1;
        for (int i = start; i < end; i++) {
            if (max < nums[i]) {
                index = i;
                max = nums[i];
            }
        }

        TreeNode *root = new TreeNode(max);
        root->left = build(nums, start, index - 1);
        root->right = build(nums, index + 1, end);
        return root;
    }
};