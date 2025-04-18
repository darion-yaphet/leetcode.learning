//
// Created by Chenguang Wang on 2024/1/28.
//

// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right) / 2;
        auto *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};