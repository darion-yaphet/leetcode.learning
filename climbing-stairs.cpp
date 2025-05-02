//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        int n0 = 0, n1 = 0, result = 1;
        for (int i = 1; i <= n; ++i) {
            n0 = n1;
            n1 = result;
            result = n0 + n1;
        }
        return result;
    }

    int climbStairs2(int n) {
        // 边界条件
        if (n <= 1) {
            return 1;
        }

        int prev1 = 1, prev2 = 1; // 初始状态：f(0) 和 f(1)

        for (int i = 2; i <= n; ++i) {
            int current = prev1 + prev2; // 当前状态
            prev2 = prev1; // 更新 prev2
            prev1 = current; // 更新 prev1
        }

        return prev1; // 最终结果
    }
};
