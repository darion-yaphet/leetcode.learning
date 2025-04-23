//
// Created by Chenguang Wang on 2024/2/2.
//
#include <vector>

using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }

        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }

    /**
     * 目标是尽可能多地抓住每次价格上涨的机会
     *
     * 如果某一天的价格比前一天高，那么我们就在前一天买入，当天卖出，赚取差价。
     * 这种策略相当于将所有连续上涨的利润累加起来。
     * 因为题目允许在同一天买入和卖出，所以我们可以直接累加所有正的差值。
     */
    int maxProfit2(vector<int>& prices) {
        int maxProfit = 0; // 初始化最大利润为 0

        for (int i = 1; i < prices.size(); ++i) {
            // 如果当前价格比前一天高，则累加差价
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }

        return maxProfit;
    }

};