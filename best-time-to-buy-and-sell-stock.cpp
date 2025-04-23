//
// Created by Chenguang Wang on 2024/1/18.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int low = INT_MAX;
        int result = 0;
        for (int price : prices) {
            low = min(low, price);
            result = max(result, price - low);
        }
        return result;
    }

    int maxProfit2(vector<int> &prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }

        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }

        return dp[len - 1][1];
    }

    /**
     * 找到一个买入点和一个卖出点，使得卖出价格减去买入价格的差值最大，并且买入必须在卖出之前。
     */
    int maxProfit3(vector<int>& prices) {
        // 如果数组为空，直接返回 0
        if (prices.empty()) {
            return 0;
        }

        int minPrice = prices[0]; // 记录历史最低价格
        int maxProfit = 0;        // 记录最大利润

        for (int i = 1; i < prices.size(); ++i) {
            // 更新历史最低价格
            minPrice = min(minPrice, prices[i]);

            // 计算当前利润，并更新最大利润
            int currentProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }

};