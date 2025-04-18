//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/valid-parentheses

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> stack;
        for (int index = 0; index < s.size(); index++) {
            if (s[index] == '(' || s[index] == '[' || s[index] == '{') {
                stack.push(s[index]);
            } else {
                if (stack.empty()) {
                    return false;
                }

                char top = stack.top();
                stack.pop();
                if (s[index] == ')' && top != '(') {
                    return false;
                }

                if (s[index] == ']' && top != '[') {
                    return false;
                }

                if (s[index] == '}' && top != '{') {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};