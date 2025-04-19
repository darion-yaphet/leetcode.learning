//
// Created by darion.yaphet on 2025/4/19.
//

#include "vector"

using namespace std;

// https://leetcode.cn/problems/count-the-number-of-fair-pairs/
class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        // 对数组进行排序
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long fairPairCount = 0;

        // 遍历每个元素 nums[i]
        for (int i = 0; i < n - 1; ++i) {
            // 找到满足 lower - nums[i] <= nums[j] <= upper - nums[i] 的范围
            int leftBound = lower - nums[i];
            int rightBound = upper - nums[i];

            // 使用 lower_bound 和 upper_bound 定位范围
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), leftBound);
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), rightBound);

            // 累加符合条件的数对数量
            fairPairCount += (right - left);
        }

        return fairPairCount;
    }
};
