//
// Created by darion.yaphet on 2025/4/16.
//

#include <iostream>
#include <vector>
#include <algorithm> // 提供 sort 函数
#include <cmath>     // 提供 abs 函数
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0; // 边界条件：数组长度不足 3

        // 对数组进行排序
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2]; // 初始化为前三数之和

        // 遍历数组，固定第一个数
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // 更新最接近的和
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                // 根据三数之和与目标值的关系调整指针
                if (sum == target) {
                    return sum; // 找到最优解，直接返回
                } else if (sum < target) {
                    ++left; // 和小于目标值，移动左指针增大和
                } else {
                    --right; // 和大于目标值，移动右指针减小和
                }
            }
        }

        return closestSum;
    }
};

// 测试代码
int main() {
    Solution solution;

    // 测试用例
    vector<int> nums1 = {-1, 2, 1, -4}; // 最接近的和是 2 (-1 + 2 + 1)
    int target1 = 1;

    vector<int> nums2 = {0, 0, 0};      // 最接近的和是 0 (0 + 0 + 0)
    int target2 = 1;

    vector<int> nums3 = {1, 1, 1, 0};   // 最接近的和是 2 (1 + 1 + 0)
    int target3 = 100;

    cout << "Test 1: " << solution.threeSumClosest(nums1, target1) << endl;
    cout << "Test 2: " << solution.threeSumClosest(nums2, target2) << endl;
    cout << "Test 3: " << solution.threeSumClosest(nums3, target3) << endl;

    return 0;
}