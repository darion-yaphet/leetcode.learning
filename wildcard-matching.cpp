//
// Created by darion.yaphet on 2025/4/30.
//

#include <string>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/wildcard-matching/
class Solution {
public:
    /**
     * 使用动态规划构建一个二维布尔数组 dp，其中 dp[i][j] 表示：
     * 字符串 s 的前 i 个字符是否可以被模式 p 的前 j 个字符匹配。
     *
     * 如果 p[j−1]==s[i−1] 或 p[j−1]== ′ ? ′ ，则 dp[i][j] = dp[i-1][j-1]
     *
     * 如果 p[j−1]== ′ ∗ ′ ，则 dp[i][j] = dp[i][j-1] || dp[i-1][j]：
     * dp[i][j-1] 表示将 '*' 匹配为空字符。
     * dp[i-1][j] 表示将 '*' 匹配为一个或多个字符。
     */
    bool isMatch(string s, string p) {
        int m = s.size(); // 输入字符串长度
        int n = p.size(); // 模式字符串长度

        // 定义动态规划表
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));

        // 初始化
        dp[0][0] = true; // 空字符串与空模式匹配
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1]; // 连续 '*' 匹配空字符串
            }
        }

        // 填充动态规划表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1]; // 单字符匹配
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; // '*' 匹配空字符或多个字符
                }
            }
        }

        return dp[m][n];
    }
};
