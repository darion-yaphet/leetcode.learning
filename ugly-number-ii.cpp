//
// Created by darion.yaphet on 2025/4/26.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/ugly-number-ii/
class Solution {
public:
    // function nthUglyNumber(n):
    // dp = array of size n
    // dp[0] = 1
    // p2, p3, p5 = 0, 0, 0
    //
    // for i from 1 to n-1:
    //     next2 = dp[p2] * 2
    //     next3 = dp[p3] * 3
    //     next5 = dp[p5] * 5
    //     dp[i] = min(next2, next3, next5)
    //
    //     if dp[i] == next2: p2 += 1
    //     if dp[i] == next3: p3 += 1
    //     if dp[i] == next5: p5 += 1
    //
    // return dp[n-1]
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
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
        return dp[n - 1];
    }
};
