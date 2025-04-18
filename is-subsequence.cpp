//
// Created by Chenguang Wang on 2024/1/28.
//

//https://leetcode.cn/problems/is-subsequence/description/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
//        int sArray[26], tArray[26];
//        if (s.size() > t.size()) {
//            return false;
//        }
//
//        for (int i = 0; i < s.size(); i++) {
//            sArray[s[i] - 'a']++;
//        }
//
//        for (int j = 0; j < t.size(); j++) {
//            tArray[t[j] - 'a']++;
//        }
//
//        for (int i = 0; i < 26; i++) {
//            if (sArray[i] > tArray[i]) {
//                return false;
//            }
//        }
//
//        return true;

        int n = s.length(), m = t.length();
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }

            j++;
        }

        return i == n;
    }

    bool isSubsequence2(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[s.size()][t.size()] == s.size();
    }

    bool isSubsequence3(string s, string t) {
        int i = 0, j = 0; // 双指针，i 指向 s，j 指向 t

        // 遍历字符串 t，尝试匹配 s 中的字符
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                ++i; // 匹配成功，移动 s 的指针
            }
            ++j; // 无论是否匹配，都需要移动 t 的指针
        }

        // 如果 i 走到了 s 的末尾，说明 s 是 t 的子序列
        return i == s.size();
    }
};
