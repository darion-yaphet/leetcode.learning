//
// Created by darion.yaphet on 2025/4/16.
//

// https://leetcode.cn/problems/basic-calculator-ii/

#include <string>

class Solution {
public:
    int calculate(std::string s) {
        int result = 0; // 最终结果
        int last = 0;   // 上一个操作数
        int num = 0;    // 当前解析的数字
        char sign = '+'; // 当前操作符，默认为 '+'

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            // 如果是数字，解析完整的数字
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // 如果是操作符或到达字符串末尾，处理上一个操作符
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (sign == '+') {
                    result += last; // 将上一个操作数加入结果
                    last = num;     // 更新上一个操作数
                } else if (sign == '-') {
                    result += last; // 将上一个操作数加入结果
                    last = -num;    // 更新上一个操作数
                } else if (sign == '*') {
                    last *= num;    // 乘法直接更新上一个操作数
                } else if (sign == '/') {
                    last /= num;    // 除法直接更新上一个操作数
                }

                // 更新操作符和重置数字
                sign = c;
                num = 0;
            }
        }

        // 将最后一个操作数加入结果
        result += last;
        return result;
    }
};