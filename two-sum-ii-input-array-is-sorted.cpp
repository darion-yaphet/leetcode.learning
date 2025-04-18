//
// Created by Chenguang Wang on 2024/2/4.
//

// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int value = numbers[left] + numbers[right];
            if (value == target) {
                return {left + 1, right + 1};
            } else if (value > target) {
                right -= 1;
            } else {
                left += 1;
            }
        }

        return {};
    }

    vector<int> twoSum2(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1; // 定义双指针

        while (left < right) {
            int sum = numbers[left] + numbers[right]; // 计算当前两数之和

            if (sum == target) {
                return {left + 1, right + 1}; // 返回结果，下标从 1 开始
            } else if (sum < target) {
                ++left; // 和小于目标值，移动左指针增大和
            } else {
                --right; // 和大于目标值，移动右指针减小和
            }
        }

        return {}; // 如果没有找到，返回空数组（理论上不会发生）
    }
};