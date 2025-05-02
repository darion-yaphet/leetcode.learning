//
// Created by Chenguang Wang on 2024/1/25.
//

// https://leetcode.cn/problems/fibonacci-number/description/

#include <vector>

using namespace std;

class Solution {
public:
    // 递归是最直观的实现方式，但效率较低，时间复杂度为 O(2^n)。
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }

    int fib1(int n) {
        if (n <= 1) {
            return n;
        }

        //        vector<int> dp(n + 1);
        //        dp[0] = 0;
        //        dp[1] = 1;
        //        for (int i = 2; i <= n; i++) {
        //            dp[i] = dp[i - 2] + dp[i - 1];
        //        }

        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }

    int fib2(int n) {
        if (n <= 1) {
            return n;
        }

        int prev2 = 0, prev1 = 1; // 分别表示 F(n-2) 和 F(n-1)
        for (int i = 2; i <= n; ++i) {
            int curr = prev1 + prev2; // 当前值 F(n)
            prev2 = prev1; // 更新 F(n-2)
            prev1 = curr; // 更新 F(n-1)
        }
        return prev1; // 最终结果是 F(n)
    }
};
