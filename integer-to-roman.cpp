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