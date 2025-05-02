//
// Created by Chenguang Wang on 2024/2/1.
//

// https://leetcode.cn/problems/minimum-falling-path-sum/description/

#include <vector>

using namespace std;

class Solution {
public:
    // dp[i][j]=matrix[i][j] + min(dp[i−1][j−1], dp[i−1][j], dp[i−1][j+1])
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = dp[i - 1][j];
                if (j > 0) {
                    mn = min(mn, dp[i - 1][j - 1]);
                }

                if (j < n - 1) {
                    mn = min(mn, dp[i - 1][j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};