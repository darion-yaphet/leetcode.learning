//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/longest-common-subsequence/description/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > memo;

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }
        return dp(text1, 0, text2, 0);
    }

    int dp(string s1, int i, string s2, int j) {
        if (s1.size() == i && s2.size() == j) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s1[i] == s2[j]) {
            memo[i][j] = dp(s1, i - 1, s2, j - 1) + 1;
        } else {
            memo[i][j] = max(dp(s1, i + 1, s2, j),
                             max(
                                 dp(s1, i, s2, j + 1),
                                 dp(s1, i + 1, s2, j + 1)
                             )
            );
        }
        return memo[i][j];
    }

    int longestCommonSubsequence2(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // 创建动态规划表，大小为 (m+1) x (n+1)
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        // 填充动态规划表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 返回最终结果
        return dp[m][n];
    }
};
