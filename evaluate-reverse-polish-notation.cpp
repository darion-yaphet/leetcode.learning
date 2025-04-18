//
// Created by Chenguang Wang on 2024/2/12.
//

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (const auto &token: tokens) {
            if (token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/") {
                int op2 = stack.top();
                stack.pop();
                int op1 = stack.top();
                stack.pop();

                if (token == "+") {
                    stack.push(op1 + op2);
                }

                if (token == "-") {
                    stack.push(op1 - op2);
                }

                if (token == "*") {
                    stack.push(op1 * op2);
                }

                if (token == "/") {
                    stack.push(op1 / op2);
                }

            } else {
                stack.push(std::atoi(token.c_str()));
            }

        }

        return stack.top();
    }
};