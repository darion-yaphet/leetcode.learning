//
// Created by darion.yaphet on 2024/10/17.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/partition-equal-subset-sum
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int total = 0;
        for (int num: nums) {
            total += num;
        }

        // 如果总和是奇数，无法均分
        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;

        // 是否能从前几个数字中选出一些，使得它们的和恰好为 i
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num: nums) {
            // 从后往前更新 dp，避免重复使用当前数字
            for (int i = target; i >= num; --i) {
                // 不选当前这个数，已经可以凑出 i
                // 或者
                // 选当前这个数，如果 i - num 可以凑出，那么加上 num 就能凑出 i
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};
