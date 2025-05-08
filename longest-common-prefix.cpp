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

    string longestCommonPrefix2(vector<string> &strs) {
        // 如果数组为空，返回空字符串
        if (strs.empty()) {
            return "";
        }

        // 初始化公共前缀为第一个字符串
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            // 不断缩短公共前缀，直到它成为当前字符串的前缀
            while (strs[i].find(prefix) != 0) {
                // 缩短公共前缀
                prefix.pop_back();

                // 如果公共前缀为空，直接返回
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        return prefix;
    }

    string longestCommonPrefix3(vector<string> &strs) {
        // 如果数组为空，返回空字符串
        if (strs.empty()) {
            return "";
        }

        auto min_length_it = std::min_element(std::begin(strs), std::end(strs),
                                              [](const std::string &a, const std::string &b) {
                                                  return a.size() < b.size();
                                              });
        int minLength = min_length_it->size();

        string result = "";
        for (int i = 0; i < minLength; ++i) {
            // 取第一个字符串的第 i 个字符
            char currentChar = strs[0][i];
            bool allMatch = true;

            for (auto & str : strs) {
                if (str[i] != currentChar) {
                    allMatch = false;
                    break;
                }
            }

            if (allMatch) {
                // 如果所有字符串的第 i 个字符相同，加入结果
                result += currentChar;
            } else {
                break;
            }
        }
        return result;
    }
};
