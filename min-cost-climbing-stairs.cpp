//
// Created by Chenguang Wang on 2024/1/25.
//

// https://leetcode.cn/problems/min-cost-climbing-stairs/description/

#include <vector>

using namespace std;

class Solution {
public:
    // dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector dp(n + 1, 0); // dp[i] 表示到达第 i 阶的最低花费

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];  // 到达楼梯顶部的最低花费
    }
};