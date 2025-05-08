//
// Created by darion.yaphet on 2024/9/23.
//

// https://leetcode.cn/problems/repeated-substring-pattern/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        unordered_map<char, int> map;
        for (char c: s) {
            map[c]++;
        }

        int value = map.begin()->second;
        return std::all_of(map.begin(), map.end(),
                           [value](const std::pair<int, int> &element) {
                               return element.second == value;
                           });
    }

    bool repeatedSubstringPattern2(std::string s) {
        if (s.empty()) {
            return false;
        }

        std::string doubled = s + s;
        // 去掉首尾字符
        std::string mid = doubled.substr(1, doubled.size() - 2);
        return mid.find(s) != std::string::npos;
    }
};
