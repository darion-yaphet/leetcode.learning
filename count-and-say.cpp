//
// Created by darion.yaphet on 2025/5/17.
//

// https://leetcode.cn/problems/count-and-say/description/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";

        for (int i = 2; i <= n; ++i) {
            string next;
            int count = 1;
            char digit = curr[0];

            for (int j = 1; j < curr.size(); ++j) {
                if (curr[j] == digit) {
                    count++;
                } else {
                    next += to_string(count) + digit;
                    digit = curr[j];
                    count = 1;
                }
            }

            // 处理最后一个数字组
            next += to_string(count) + digit;
            curr = next;
        }

        return curr;
    }

    string countAndSay2(int n) {
        if (n <= 0) return "";
        if (n == 1) return "1";

        string result = "1";

        // 从第2项开始逐项生成
        for (int i = 2; i <= n; i++) {
            result = getNextTerm(result);
        }

        return result;
    }

private:
    // 生成下一项：对当前字符串进行行程长度编码
    string getNextTerm(const string &s) {
        string next = "";
        int count = 1; // 计数器，记录连续相同字符的个数

        // 遍历当前字符串的每个字符
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && s[i] == s[i + 1]) {
                // 情况1：当前字符和下一个字符相同
                count++; // 计数加1
            } else {
                // 情况2：当前字符和下一个字符不同（或到达末尾）
                // 添加描述：数量 + 数字
                next += to_string(count) + s[i];
                count = 1; // 重置计数器
            }
        }

        return next;
    }
};
