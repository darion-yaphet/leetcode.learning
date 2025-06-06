//
// Created by Chenguang Wang on 2024/3/3.
//

// https://leetcode.cn/problems/palindrome-partitioning/

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(const string &s, int startIndex) {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            // 是回文子串
            if (isPalindrome(s, startIndex, i)) {
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
                // 不是回文，跳过
            } else {
                continue;
            }

            backtracking(s, i + 1); // 寻找i+1为起始位置的子串
            path.pop_back(); // 回溯过程，弹出本次已经填在的子串
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};
