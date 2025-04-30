//
// Created by darion.yaphet on 2025/4/30.
//

#include <string>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/palindrome-partitioning-ii/
class Solution {
public:
    // isPalindrome[i][j]=(s[i]==s[j])&isPalindrome[i+1][j−1]
    int minCut(string s) {
        int n = s.size();

        // Step 1: 预处理回文表 isPalindrome[i][j]
        // 如果 s[i]==s[j]，并且子串长度小于等于 2 或者中间部分是回文，则 s[i:j] 是回文。
        vector<vector<bool> > isPalindrome(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
                    // 单个字符一定是回文，即 isPalindrome[i][i] = true。
                    // 如果两个相邻字符相等，则它们组成的子串也是回文，即 isPalindrome[i][i+1] = (s[i] == s[i+1])。
                    isPalindrome[i][j] = true;
                }
            }
        }

        // Step 2: 动态规划求解最少分割次数
        // dp[i] 表示前 i 个字符的最少分割次数
        vector<int> dp(n, INT32_MAX);
        for (int i = 0; i < n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 0; // 如果整个子串是回文，则不需要分割
            } else {
                for (int j = 0; j < i; ++j) {
                    if (isPalindrome[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
