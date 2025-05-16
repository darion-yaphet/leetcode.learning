//
// Created by darion.yaphet on 2025/5/18.
//

#include <string>
#include <stack>

using namespace std;

// https://leetcode.cn/problems/score-of-parentheses/
class Solution {
public:
    /**
     * 遇到 '('：将 0 压入栈中，表示当前层级开始
     *
     * 遇到 ')'：
     * 弹出栈顶元素 top
     * 如果 top == 0，说明是空括号 "()"，得 1 分，压回 1
     * 否则，说明是嵌套结构，总分是 top * 2，压回结果
     * 然后把当前层级得分加到上一层
     */
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // 初始分数为 0

        for (char c: s) {
            if (c == '(') {
                st.push(0);
            } else {
                int top = st.top();
                st.pop();

                if (top == 0) {
                    // "()" 得 1 分
                    st.top() += 1;
                } else {
                    // "(A)" 得 2*A 分
                    st.top() += 2 * top;
                }
            }
        }

        return st.top();
    }
};
