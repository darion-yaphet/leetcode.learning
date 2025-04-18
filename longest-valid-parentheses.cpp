//
// Created by darion.yaphet on 2025/4/16.
//

// https://leetcode.cn/problems/longest-valid-parentheses/

#include <string>
#include <stack>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stk;
        stk.push(-1); // 初始化栈，添加虚拟边界
        int maxLength = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i); // 左括号入栈
            } else {
                stk.pop(); // 弹出栈顶元素
                if (stk.empty()) {
                    stk.push(i); // 更新新的边界
                } else {
                    maxLength = std::max(maxLength, i - stk.top());
                }
            }
        }
        return maxLength;
    }

    int longestValidParentheses2(std::string s) {
        int left = 0, right = 0, maxLength = 0;

        // 从左到右遍历
        for (char c: s) {
            if (c == '(') {
                ++left;
            } else {
                ++right;
            }

            if (left == right) {
                maxLength = std::max(maxLength, 2 * right);
            } else if (right > left) {
                left = right = 0; // 重置计数
            }
        }

        left = right = 0;

        // 从右到左遍历
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }

            if (left == right) {
                maxLength = std::max(maxLength, 2 * left);
            } else if (left > right) {
                left = right = 0; // 重置计数
            }
        }

        return maxLength;
    }
};
