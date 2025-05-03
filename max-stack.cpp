//
// Created by darion.yaphet on 2025/5/3.
//

#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
private:
    stack<int> mainStack; // 主栈，存储所有元素
    stack<int> maxStack; // 辅助栈，存储当前最大值

public:
    // 将元素 x 压入栈中
    void push(int x) {
        mainStack.push(x);
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x); // 更新辅助栈
        } else {
            maxStack.push(maxStack.top()); // 重复压入当前最大值
        }
    }

    // 移除栈顶元素并返回这个值
    int pop() {
        int topValue = mainStack.top();
        mainStack.pop();
        maxStack.pop(); // 同时弹出辅助栈栈顶
        return topValue;
    }

    // 返回栈顶元素
    int top() {
        return mainStack.top();
    }

    // 返回栈中最大元素
    int peekMax() {
        return maxStack.top();
    }

    // 返回栈中最大的元素，并将其删除
    int popMax() {
        int maxValue = maxStack.top();
        stack<int> tempStack; // 临时栈

        // 找到并移除主栈中最靠近栈顶的最大值
        while (mainStack.top() != maxValue) {
            tempStack.push(mainStack.top());
            mainStack.pop();
            maxStack.pop(); // 同步更新辅助栈
        }

        // 移除最大值
        mainStack.pop();
        maxStack.pop();

        // 将临时栈中的元素重新压回主栈
        while (!tempStack.empty()) {
            push(tempStack.top());
            tempStack.pop();
        }

        return maxValue;
    }
};

// 测试代码
int main() {
    MaxStack maxStack;
    maxStack.push(5);
    maxStack.push(1);
    maxStack.push(5);

    cout << "最大值: " << maxStack.peekMax() << endl; // 输出: 5
    cout << "栈顶元素: " << maxStack.top() << endl; // 输出: 5

    cout << "移除栈顶元素: " << maxStack.pop() << endl; // 输出: 5
    cout << "最大值: " << maxStack.peekMax() << endl; // 输出: 5

    cout << "移除最大值: " << maxStack.popMax() << endl; // 输出: 5
    cout << "栈顶元素: " << maxStack.top() << endl; // 输出: 1

    return 0;
}
