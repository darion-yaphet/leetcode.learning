//
// Created by Chenguang Wang on 2024/2/1.
//

// https://leetcode.cn/problems/house-robber-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        return max(robRange(nums, 0, size - 2),
                   robRange(nums, 1, size - 1));
    }

    int robRange(vector<int> &nums, int start, int end) {
        int n = nums.size();
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp_i = 0;
        for (int i = end; i >= start; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }

    /**
     * dp[i]=max(dp[i−1],dp[i−2]+nums[i])
     */
    int rob2(vector<int> &nums) {
        int n = nums.size();

        // 没有房屋，返回 0
        if (n == 0) return 0;

        // 只有一间房屋，直接返回其金额
        if (n == 1) return nums[0];

        // 分解为两个子问题：
        // 1. 不偷第一个房屋（从第 2 个房屋到第 n 个房屋）
        // 2. 不偷最后一个房屋（从第 1 个房屋到第 n-1 个房屋）
        return max(robHelper(nums, 0, n - 2), robHelper(nums, 1, n - 1));
    }

    int robHelper(const vector<int> &nums, int start, int end) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = start; i <= end; ++i) {
            int current = max(prev1, prev2 + nums[i]); // 当前状态的最大金额
            prev2 = prev1; // 更新 dp[i-2]
            prev1 = current; // 更新 dp[i-1]
        }

        return prev1; // 返回最终结果
    }
};
