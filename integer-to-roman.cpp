//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/integer-to-roman/description/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        pair<int, string> pairs[] = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"},
        };

        string roman;
        // 从映射表中最大的数值开始，检查当前数值是否大于等于该数值。
        // 如果是，则将对应的符号添加到结果字符串中，并从当前数值中减去该数值。
        // 重复上述过程，直到数值为零。
        for (const auto &[key, value]: pairs) {
            while (num >= key) {
                num -= key;
                roman += value;
            }

            if (num == 0) {
                break;
            }
        }

        return roman;
    }
};