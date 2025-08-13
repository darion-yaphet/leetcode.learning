//
// Created by Chenguang Wang on 2024/2/22.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    // 中心扩展法
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLength) {
        // 使用 while 循环进行双向扩展，条件是 left 和 right 指针都在字符串范围内，并且指向的字符相同。
        // 每次成功匹配时更新最长回文子串的起始位置和长度。
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                start = left;
                maxLength = currentLength;
            }
            --left;
            ++right;
        }
    }

public:
    string longestPalindrome2(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }

            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int> > dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }

    // 每个字符（以及每对相邻字符之间的位置）都可以作为回文的中心，然后从这个中心向外扩展来找到最长的回文子串。
    // 奇数长度回文串：以一个字符为中心（例如 "aba"），可以想象成有一个单独的字符在最中间。
    // 偶数长度回文串：以两个相邻字符之间的一个虚拟中心为中心（例如 "abba"），可以想象成在这两个字符之间的空隙作为中心。
    // 遍历字符串中的每一个字符，将其视为潜在的回文中心。
    // 对于每个中心，尝试向两侧扩展，检查是否能够形成回文。
    //      如果当前字符与它左侧或右侧的字符相等，则继续比较下一个外层的字符。
    //      如果不相等，或者到达了字符串的边界，则停止扩展。
    string longestPalindrome3(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            // 奇数长度的回文串，以 i 为中心
            expandAroundCenter(s, i, i, start, maxLength);

            // 偶数长度的回文串，以 i 和 i+1 为中心
            expandAroundCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }
};
