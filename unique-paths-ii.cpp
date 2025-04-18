//
// Created by Chenguang Wang on 2024/1/25.
//

// https://leetcode.cn/problems/unique-paths-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }

        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles2(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 创建一个一维数组 dp，初始化为 0
        vector<int> dp(n, 0);

        // 初始化起点
        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        // 填充 dp 数组
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // 障碍物，路径数为 0
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // 当前值等于上方的值加上左方的值
                }
            }
        }

        return dp[n - 1]; // 返回右下角的路径数
    }
};
