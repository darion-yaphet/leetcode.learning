//
// Created by Chenguang Wang on 2024/2/22.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
            } else {
                dp[i][0] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
            }
        }

        if (n == 1 && m == 1) {
            return dp[0][0];
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j - 1] == '1' &&
                    matrix[i - 1][j] == '1' &&
                    matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                } else {
                    if (matrix[0][i] == '1') {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                }

                result = max(result, dp[i][j]);
            }
        }

        return result * result;
    }

    int maximalSquare2(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int> > dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }

    /**
     * 如果 matrix[i][j] == '1'：
     * dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
     * 否则：
     * dp[i][j] = 0;
     */
    int maximalSquar3(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int maxSide = 0;

        // 初始化第一行和第一列
        for (int i = 0; i < m; ++i) {
            dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            maxSide = max(maxSide, dp[i][0]);
        }

        for (int j = 0; j < n; ++j) {
            dp[0][j] = (matrix[0][j] == '1') ? 1 : 0;
            maxSide = max(maxSide, dp[0][j]);
        }

        // 动态规划填表
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    maxSide = max(maxSide, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxSide * maxSide;
    }
};
