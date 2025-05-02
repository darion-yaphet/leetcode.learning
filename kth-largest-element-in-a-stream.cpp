//
// Created by darion.yaphet on 2025/5/1.
//

#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
    int k; // 第 k 大元素
    priority_queue<int, vector<int>, greater<int> > minHeap; // 最小堆

public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (auto num: nums) {
            add(num); // 调用 add 方法初始化堆
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val); // 如果堆的大小小于 k，直接插入
        } else if (val > minHeap.top()) {
            minHeap.pop(); // 弹出堆顶元素
            minHeap.push(val); // 插入新值
        }
        return minHeap.top(); // 返回堆顶元素（即第 k 大元素）
    }
};
