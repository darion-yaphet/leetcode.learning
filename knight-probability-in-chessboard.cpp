//
// Created by Chenguang Wang on 2024/3/3.
//
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {{-2, -1},
                                {-2, 1},
                                {2,  -1},
                                {2,  1},
                                {-1, -2},
                                {-1, 2},
                                {1,  -2},
                                {1,  2}};

public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for (int step = 0; step <= k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (step == 0) {
                        dp[step][i][j] = 1;
                    } else {
                        for (const auto &dir: dirs) {
                            int ni = i + dir[0];
                            int nj = j + dir[1];
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                                dp[step][i][j] += dp[step - 1][ni][nj] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};