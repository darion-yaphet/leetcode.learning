//
// Created by Chenguang Wang on 2024/2/20.
//

// https://leetcode.cn/problems/next-greater-element-iii

#include <string>

class Solution {
public:
    int nextGreaterElement(int n) {
        auto nums = std::to_string(n);
        int i = (int) nums.length() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i < 0) {
            return -1;
        }

        int j = nums.size() - 1;
        while (j >= 0 && nums[i] >= nums[j]) {
            j--;
        }

        std::swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        long ans = stol(nums);
        return ans > INT_MAX ? -1 : ans;
    }
};
