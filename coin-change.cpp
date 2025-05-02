//
// Created by Chenguang Wang on 2024/2/1.
//

// https://leetcode.cn/problems/coin-change/description/

#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        // 定义 dp 数组，dp[i] 表示凑成金额 i 所需的最少硬币个数
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (auto coin: coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }

    int coinChange2(vector<int> &coins, int amount) {
        return dp(coins, amount);
    }

    int dp(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }

        int res = INT_MAX;
        for (auto coin: coins) {
            int subProblem = dp(coins, amount - coin);
            if (subProblem == -1) {
                continue;
            }
            res = min(res, subProblem + 1);
        }

        return res == INT_MAX ? -1 : res;
    }
};