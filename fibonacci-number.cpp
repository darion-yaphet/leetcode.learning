//
// Created by Chenguang Wang on 2024/1/25.
//

// https://leetcode.cn/problems/fibonacci-number/description/

#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
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
};