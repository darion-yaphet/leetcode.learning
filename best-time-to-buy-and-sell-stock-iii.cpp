//
// Created by Chenguang Wang on 2024/2/2.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }

        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return dp[prices.size() - 1][4];
    }

    /**
     * 通过一次遍历数组并维护状态变量来解决这个问题。
     *
     *
     */
    int maxProfit2(vector<int>& prices) {
        if (prices.empty()) return 0; // 如果数组为空，直接返回 0

        // 初始化状态变量
        int buy1 = INT32_MIN, sell1 = 0;
        int buy2 = INT32_MIN, sell2 = 0;

        for (int price : prices) {
            // 更新第一次买入和卖出的状态
            buy1 = max(buy1, -price);              // 第一次买入，尽量以低价买入
            sell1 = max(sell1, buy1 + price);      // 第一次卖出，计算利润

            // 更新第二次买入和卖出的状态
            buy2 = max(buy2, sell1 - price);       // 第二次买入，基于第一次卖出的利润
            sell2 = max(sell2, buy2 + price);      // 第二次卖出，计算最终利润
        }

        return sell2; // 返回第二次卖出后的最大利润
    }
};