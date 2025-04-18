//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <string>

using namespace std;

class Solution {
public:
    int strStr(const string& haystack, const string &needle) {
        auto result = haystack.find(needle);
        if (result == string::npos) {
            return -1;
        }

        return result;
    }
};