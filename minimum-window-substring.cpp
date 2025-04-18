//
// Created by Chenguang Wang on 2024/2/12.
//

// https://leetcode.cn/problems/minimum-window-substring
// 思路：
// 1. 创建一个滑动窗口，窗口的左右边界分别为 left 和 right，初始时，left = 0，right = 0。
// 2. 创建一个哈希表 need，用于记录字符串 t 中每个字符出现的次数。
// 3. 创建一个哈希表 window，用于记录滑动窗口中每个字符出现的次数。
// 4. 创建一个变量 valid，用于记录窗口中满足 need 条件的字符个数。
// 5. 创建一个变量 start，用于记录最小覆盖子串的起始索引。
// 6. 创建一个变量 len，用于记录最小覆盖子串

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (const auto &c: t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;

        // 最小覆盖子串的起始索引及长度
        int start = 0;
        int len = INT_MAX;
        while (right < s.size()) {
            char c = s[right];

            // 扩大窗口
            right += 1;

            if (need.count(c)) {
                window[c] += 1;
                if (need[c] == window[c]) {
                    valid++;
                }
            }

            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {
                // 更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                char d = s[left];

                // 缩小窗口
                left++;

                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ?
               "" : s.substr(start, len);
    }
};