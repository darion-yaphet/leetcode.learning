//
// Created by Chenguang Wang on 2024/2/14.
//
#include <vector>

using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // 如果数组为空，直接返回 0
        if (prices.empty()) {
            return 0;
        }

        int hold = INT32_MIN, sold = 0, cooldown = 0;

        for (int price : prices) {
            int prevHold = hold, prevSold = sold, prevCooldown = cooldown;

            // 更新持有股票的状态
            hold = max(prevHold, prevCooldown - price);

            // 更新卖出股票的状态
            sold = prevHold + price;

            // 更新冷冻期的状态
            cooldown = max(prevCooldown, prevSold);
        }

        // 最大利润是最后一天的 sold 或 cooldown 中的最大值
        return max(sold, cooldown);
    }
};