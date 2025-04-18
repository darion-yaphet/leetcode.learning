//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/reverse-words-in-a-string/description/

#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        std::stringstream stream(s);
        string token;
        stack<string> stack;
        while (stream >> token) {
            stack.push(token);
        }

        string result;
        while (!stack.empty()) {
            result += stack.top();
            result += " ";
            stack.pop();
        }

        result.pop_back();
        return result;
    }
};