//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/roman-to-integer/description/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };

        int result = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            int value = map[s[i]];

            // 如果当前字符的值小于下一个字符的值，则是减法情况
            if (i < len - 1 && value < map[s[i + 1]]) {
                result -= value;
            } else {
                // 否则是加法情况
                result += value;
            }
        }
        return result;
    }
};