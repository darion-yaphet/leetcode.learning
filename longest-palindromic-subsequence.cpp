//
// Created by Chenguang Wang on 2024/2/25.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        int dp[size][size];

        for (int i = 0; i < size; i++) {
            dp[i][i] = 1;
        }

        for (int i = size - 1; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][size - 1];
    }

    int longestPalindromeSubseq2(string s) {
        int n = s.size();
        // 定义 DP 数组
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // 初始化：单个字符的回文子序列长度为 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // 按照子区间长度从小到大填充 DP 表
        for (int len = 2; len <= n; ++len) { // 子区间长度从 2 开始
            // 遍历所有起始位置
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // 区间右端点
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        // 返回整个字符串的最长回文子序列长度
        return dp[0][n-1];
    }
};