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


    /**
     * 如果偷第 i 间房屋，则不能偷第 i-1 间房屋：dp[i] = dp[i-2] + nums[i]。
     * 如果不偷第 i 间房屋，则可以保留前 i-1 间房屋的最大金额：dp[i] = dp[i-1]。
     *
     * dp[i]=max(dp[i−1],dp[i−2]+nums[i])
     */
    int rob3(vector<int> &nums) {
        int n = nums.size();

        // 没有房屋，返回 0
        if (n == 0) return 0;

        // 只有一间房屋，直接返回其金额
        if (n == 1) return nums[0];

        // 初始化两个变量，分别表示前一间房屋和前两间房屋的最大金额
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = 0; i < n; ++i) {
            int current = max(prev1, prev2 + nums[i]); // 当前状态的最大金额
            prev2 = prev1; // 更新 dp[i-2]
            prev1 = current; // 更新 dp[i-1]
        }

        return prev1; // 返回最终结果
    }
};
