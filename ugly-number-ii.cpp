//
// Created by darion.yaphet on 2025/4/26.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/ugly-number-ii/
class Solution {
public:
    int nthUglyNumber(int n) {
        // 初始化 dp 数组，dp[i] 表示第 i+1 个丑数
        vector<int> dp(n);
        dp[0] = 1;

        // 定义三个指针，分别对应乘以 2、3 和 5 的位置
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
            // 计算下一个丑数
            int next2 = dp[p2] * 2;
            int next3 = dp[p3] * 3;
            int next5 = dp[p5] * 5;

            dp[i] = min({next2, next3, next5});

            if (dp[i] == next2) {
                ++p2;
            }

            if (dp[i] == next3) {
                ++p3;
            }

            if (dp[i] == next5) {
                ++p5;
            }
        }

        // 返回第 n 个丑数
        return dp[n - 1];
    }
};
