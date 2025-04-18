//
// Created by Chenguang Wang on 2024/2/13.
//

#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;
public:
    MyQueue() {

    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                int value = inStack.top();
                inStack.pop();
                outStack.push(value);
            }
        }

        int top = outStack.top();
        outStack.pop();
        return top;
    }

    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                int value = inStack.top();
                inStack.pop();
                outStack.push(value);
            }
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */