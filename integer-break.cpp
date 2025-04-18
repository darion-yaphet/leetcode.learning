//
// Created by Chenguang Wang on 2024/1/25.
//

//https://leetcode.cn/problems/integer-break/

#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }

            dp[i] = curMax;
        }
        return dp[n];
    }

    // dp[i] = max(dp[i], max(j⋅(i−j), j⋅dp[i−j]))
    int integerBreak2(int n) {
        // dp[i] 表示数字 i 的最大乘积
        vector<int> dp(n + 1, 0);

        // 初始化边界条件
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // 两种选择：拆分 i 为 j 和 i-j，或者不拆分 i-j
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};
