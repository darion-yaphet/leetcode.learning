//
// Created by Chenguang Wang on 2024/1/25.
//

// https://leetcode.cn/problems/unique-paths/description/

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    int uniquePaths2(int m, int n) {
        // 创建一个二维数组 dp，初始化为 0
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

        // 填充 dp 数组
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1]; // 返回右下角的路径数
    }

    int uniquePaths3(int m, int n) {
        // 创建一个一维数组 dp，初始化为 1
        std::vector<int> dp(n, 1);

        // 填充 dp 数组
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; // 当前值等于上方的值加上左方的值
            }
        }

        return dp[n - 1]; // 返回右下角的路径数
    }
};