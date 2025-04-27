//
// Created by darion.yaphet on 2025/4/27.
//

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk; // 用于存储中间结果和符号
        int result = 0; // 当前计算结果
        int currentNumber = 0; // 当前解析到的数字
        int sign = 1; // 当前符号，1 表示正，-1 表示负

        for (char ch: s) {
            if (isdigit(ch)) {
                // 构造多位数字
                currentNumber = currentNumber * 10 + (ch - '0');
            } else if (ch == '+') {
                // 遇到加号，更新结果
                result += sign * currentNumber;
                currentNumber = 0;
                sign = 1; // 设置为正号
            } else if (ch == '-') {
                // 遇到减号，更新结果
                result += sign * currentNumber;
                currentNumber = 0;
                sign = -1; // 设置为负号
            } else if (ch == '(') {
                // 遇到左括号，将当前结果和符号压入栈
                stk.push(result);
                stk.push(sign);
                result = 0; // 重置结果
                sign = 1; // 重置符号
            } else if (ch == ')') {
                // 遇到右括号，计算括号内的结果
                result += sign * currentNumber;
                currentNumber = 0;

                // 弹出栈顶的符号和结果
                int stackSign = stk.top();
                stk.pop();
                int lastResult = stk.top();
                stk.pop();

                // 合并括号内外的结果
                result = lastResult + stackSign * result;
            }
            // 忽略空格
        }

        // 处理最后一个数字
        result += sign * currentNumber;
        return result;
    }
};
