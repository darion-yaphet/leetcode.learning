//
// Created by darion.yaphet on 2025/5/8.
//

#include <list>

using namespace std;

// https://leetcode.cn/problems/design-front-middle-back-queue/
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
    }

    // 将 val 添加到队列的最前面
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    // 将 val 添加到队列的正中间
    void pushMiddle(int val) {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }

    // 将 val 添加到队列的最后面
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    // 删除并返回队列的最前面的元素
    int popFront() {
        if (left.empty()) return -1;
        int val = left.front();
        left.pop_front();
        balance();
        return val;
    }

    // 删除并返回队列的正中间的元素
    int popMiddle() {
        if (left.empty()) return -1;
        int val = left.back();
        left.pop_back();
        balance();
        return val;
    }

    // 删除并返回队列的最后面的元素
    int popBack() {
        if (right.empty()) {
            if (left.empty()) return -1;
            int val = left.back();
            left.pop_back();
            return val;
        }
        int val = right.back();
        right.pop_back();
        balance();
        return val;
    }

private:
    list<int> left; // 存储前半部分
    list<int> right; // 存储后半部分

    // 平衡两个链表的大小
    void balance() {
        if (left.size() > right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        } else if (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
