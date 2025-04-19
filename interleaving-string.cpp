//
// Created by darion.yaphet on 2025/4/19.
//

#include <string>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/interleaving-string/
class Solution {
public:
    /**
     * 如果 s1[i-1] == s3[i+j-1]，则可以从 dp[i-1][j] 转移到 dp[i][j]。
     * 如果 s2[j-1] == s3[i+j-1]，则可以从 dp[i][j-1] 转移到 dp[i][j]。
     *
     * dp[i][j]=(dp[i−1][j]∧s1[i−1]==s3[i+j−1]) V (dp[i][j−1]∧s2[j−1]==s3[i+j−1])
     */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();

        // 如果 s3 的长度不等于 s1 和 s2 长度之和，直接返回 false
        if (m + n != s3.size()) {
            return false;
        }

        // 定义 DP 数组
        vector dp(m + 1, vector<bool>(n + 1, false));

        // 初始化 dp[0][0]
        dp[0][0] = true;

        // 初始化第一列（仅用 s1 匹配 s3）
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // 初始化第一行（仅用 s2 匹配 s3）
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // 填充 DP 表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        // 返回最终结果
        return dp[m][n];
    }
};
