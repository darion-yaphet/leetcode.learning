//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <string>

using namespace std;

class Solution {
public:
    int strStr(const string &haystack, const string &needle) {
        auto result = haystack.find(needle);
        if (result == string::npos) {
            return -1;
        }

        return result;
    }

    int strStr2(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        // 边界条件：如果 needle 是空字符串，返回 0
        if (m == 0) {
            return 0;
        }

        // 边界条件：如果 needle 比 haystack 长，返回 -1
        if (m > n) {
            return -1;
        }

        // 遍历 haystack 的每个可能的起始位置
        for (int i = 0; i <= n - m; ++i) {
            // 检查从 i 开始的子串是否等于 needle
            if (haystack.substr(i, m) == needle) {
                return i; // 找到匹配，返回下标
            }
        }

        return -1; // 未找到匹配，返回 -1
    }
};
