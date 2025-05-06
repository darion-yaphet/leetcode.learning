//
// Created by darion.yaphet on 2025/5/6.
//

#include <vector>
#include <queue>

using namespace std;

// https://leetcode.cn/problems/minimum-pair-removal-to-sort-array-i/
class Solution {
public:
    // 使用一个最小堆（优先队列）来动态维护当前数组中的所有相邻元素对及其和。
    // 每次从堆中取出和最小的一对，将其合并为一个新的值，并更新数组。
    // 合并后需要重新计算新的相邻元素对，并插入到堆中。
    int minimumPairRemoval(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > minHeap;
        for (int i = 0; i < n - 1; ++i) {
            minHeap.push({nums[i] + nums[i + 1], i});
        }

        int operations = 0; // 记录操作次数
        while (!isNonDecreasing(nums)) {
            // 取出和最小的一对
            auto [sum, left] = minHeap.top();
            minHeap.pop();

            // 合并这对元素
            nums[left] = sum;
            nums.erase(nums.begin() + left + 1); // 删除右边的元素
            --n; // 更新数组长度

            // 更新堆中的相邻元素对
            if (left > 0) {
                minHeap.push({nums[left - 1] + nums[left], left - 1});
            }

            if (left < n - 1) {
                minHeap.push({nums[left] + nums[left + 1], left});
            }

            ++operations; // 增加操作计数
        }
        return operations;
    }

    // 判断数组是否是非递减的
    bool isNonDecreasing(const vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
