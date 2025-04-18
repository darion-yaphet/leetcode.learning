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
};
