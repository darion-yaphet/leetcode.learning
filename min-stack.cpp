//
// Created by Chenguang Wang on 2024/1/26.
//

#include <stack>

using namespace std;

/*
 * 维护两个栈：
 * 主栈（mainStack） ：用于存储所有元素。
 * 辅助栈（minStack） ：用于存储当前栈中的最小值。
 */
class MinStack {
private:
    stack<int> mainStack; // 主栈，存储所有元素
    stack<int> minStack; // 辅助栈，存储当前最小值

public:
    MinStack() {
    }

    void push(int val) {
        mainStack.push(val); // 将 val 压入主栈
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val); // 更新辅助栈
        } else {
            minStack.push(minStack.top()); // 重复压入当前最小值
        }
    }

    void pop() {
        mainStack.pop(); // 弹出主栈栈顶
        minStack.pop(); // 同时弹出辅助栈栈顶
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
