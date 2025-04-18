//
// Created by Chenguang Wang on 2024/2/7.
//
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int result = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;

            // 判断左侧窗口是否要收缩
            while (window[c] > 1) {
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                window[d]--;
            }

            result = max(result, right - left);
        }
        return result;
    }

    // 使用两个指针 left 和 right 表示当前窗口的左右边界。
    // right 从左到右遍历字符串，逐步扩展窗口。
    // 如果发现窗口内有重复字符（通过 unordered_set 判断），则移动左边界 left 缩小窗口，直到窗口内没有重复字符。
    int lengthOfLongestSubstring2(string s) {
        std::unordered_set<char> charSet; // 用于存储当前窗口中的字符
        int maxLength = 0;           // 记录最长子串的长度
        int left = 0;                // 滑动窗口的左边界

        for (int right = 0; right < s.size(); ++right) {
            // 如果当前字符已经在集合中，移动左边界直到没有重复字符
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                ++left;
            }
            // 将当前字符加入集合
            charSet.insert(s[right]);
            // 更新最大长度
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};