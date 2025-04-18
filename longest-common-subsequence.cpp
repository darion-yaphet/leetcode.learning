//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/longest-common-subsequence/description/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

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
};