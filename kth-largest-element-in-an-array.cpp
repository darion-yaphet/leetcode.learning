//
// Created by Chenguang Wang on 2024/1/28.
//

// https://leetcode.cn/problems/kth-largest-element-in-an-array

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> queue;
        for (const auto &num: nums) {
            queue.push(num);
        }

        int result;
        for (int i = 0; i < k; i++) {
            result = queue.top();
            queue.pop();
        }

        return result;
    }
};