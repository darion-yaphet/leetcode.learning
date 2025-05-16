//
// Created by darion.yaphet on 2025/4/27.
//

#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0; // 字符串索引
        int n = s.size();
        int sign = 1; // 符号，默认为正
        long result = 0; // 结果，使用 long 防止溢出

        // 1. 跳过前导空格
        while (i < n && s[i] == ' ') {
            ++i;
        }

        // 2. 处理符号
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // 3. 解析数字
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 检查是否超出 32 位整数范围
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            ++i;
        }

        // 4. 返回结果
        return result * sign;
    }

    int myAtoi2(string s) {
        int i = 0;
        int n = s.size();

        // Step 1: Skip leading whitespace
        while (i < n && isspace(s[i])) {
            ++i;
        }

        // Step 2: Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // Step 3: Skip leading zeros
        while (i < n && s[i] == '0') {
            ++i;
        }

        // Step 4: Read digits and build number
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Early stop if overflow
            if (result > INT_MAX) {
                break;
            }
            ++i;
        }

        result *= sign;
        // Step 5: Clamp to 32-bit signed integer range
        if (result < INT_MIN) {
            return INT_MIN;
        }

        if (result > INT_MAX) {
            return INT_MAX;
        }
        return static_cast<int>(result);
    }
};
