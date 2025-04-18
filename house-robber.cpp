//
// Created by Chenguang Wang on 2024/2/1.
//

// https://leetcode.cn/problems/house-robber/description/

#include <vector>

using namespace std;

class Solution {
public:

    int rob2(vector<int> &nums) {
        int n = nums.size();
        // dp[i] = x 表示：
        // 从第 i 间房子开始抢劫，最多能抢到的钱为 x
        // base case: dp[n] = 0
        int dp[n + 2];
        for (int i = 0; i < n - 1; i++) {
            dp[i] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }

    int rob(vector<int> &nums) {
        int size = nums.size();
        int memo[size];
        for (int i = 0; i < size; i++) {
            memo[i] = -1;
        }

        return dp(nums, 0, memo);
    }

    int dp(vector<int> &nums, int start, int memo[]) {
        if (start >= nums.size()) {
            return 0;
        }

        if (memo[start] != -1) {
            return memo[start];
        }

        int result = max(nums[start] + dp(nums, start + 2, memo), dp(nums, start + 1, memo));
        memo[start] = result;
        return result;
    }
};