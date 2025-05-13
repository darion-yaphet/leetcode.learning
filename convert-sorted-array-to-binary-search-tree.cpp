//
// Created by Chenguang Wang on 2024/1/28.
//

// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 利用数组的有序性，选择数组的中间元素作为根节点。
     * 数组的左半部分用于构建左子树，右半部分用于构建右子树。
     * 递归地对左右两部分重复上述过程，直到数组为空。
     */
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        auto *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};
