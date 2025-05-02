//
// Created by Chenguang Wang on 2024/2/1.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// https://leetcode.cn/problems/edit-distance
class Solution {
public:
    int minDistance2(string word1, string word2) {
        vector<vector<int> > dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (n * m == 0) {
            return n + m;
        }

        int dp[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }
        return dp[m][n];
    }

    int minDistance3(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        // 定义 dp 数组，dp[i][j] 表示将 word1 的前 i 个字符转换为 word2 的前 j 个字符的最少操作数
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        // 初始化边界条件
        // word1 前 i 个字符转换为空字符串需要 i 次删除
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        // 空字符串转换为 word2 前 j 个字符需要 j 次插入
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        // 动态规划填充 dp 数组
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // 字符相同，无需操作
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[m][n]; // 返回将 word1 转换为 word2 的最少操作数
    }
};
