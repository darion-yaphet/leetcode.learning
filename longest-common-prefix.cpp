//
// Created by Chenguang Wang on 2024/2/12.
//

// https://leetcode.cn/problems/longest-common-prefix/description/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }

        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < count; ++j) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};