//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
    };

    vector<string> result;
    string s;

    void backtracking(string digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }

        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (char letter : letters) {
            s.push_back(letter);
            backtracking(digits, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
};