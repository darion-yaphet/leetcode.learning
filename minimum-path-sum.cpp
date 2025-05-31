//
// Created by Chenguang Wang on 2024/2/4.
//
#include <vector>

using namespace std;

// https://leetcode.cn/problems/minimum-path-sum/description/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];

        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int j = 1; j < m; j++) {
            dp[j][0] = dp[j - 1][0] + grid[j][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }

    int minPathSum2(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);

        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j)
            dp[j] = dp[j - 1] + grid[0][j];

        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};
