//
// Created by Chenguang Wang on 2024/1/20.
//

//https://leetcode.cn/problems/valid-palindrome/description/

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }

    bool isPalindrome2(string s) {
        string cleaned; // 存储清理后的字符串

        // 遍历字符串，保留字母和数字，并将大写字母转换为小写
        for (char c: s) {
            if (isalnum(c)) {
                // 检查是否是字母或数字
                cleaned += tolower(c); // 转换为小写并添加到清理后的字符串
            }
        }

        // 检查清理后的字符串是否是回文
        int left = 0, right = cleaned.size() - 1;
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false; // 如果左右字符不相等，则不是回文
            }
            ++left;
            --right;
        }

        return true; // 如果遍历结束，说明是回文
    }
};
