//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/coin-change-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 凑成金额 0 只有一种组合方式（不使用任何硬币）。

        // dp[i] += dp[i−coin] 对于每个硬币面额 coin
        // 遍历每种硬币面额
        for (int coin: coins) {
            // 更新金额从 coin 到 amount
            for (int j = coin; j <= amount; j++) {
                // 状态转移
                // 如果当前金额 i 可以通过使用一枚 coin 来从金额 i - coin 转移到金额 i，
                // 则将 dp[i - coin] 的组合数累加到 dp[i]。
                // 说明 凑成 dp[i] 需要 一个coin面额的硬币 加上 dp[i - coin]种方法。
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};
