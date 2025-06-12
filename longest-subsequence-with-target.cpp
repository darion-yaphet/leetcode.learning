//
// Created by darion.yaphet on 2025/6/11.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestSubarrayWithTargetAndSumLimit(const vector<int>& nums, int K, int target) {
    int n = nums.size();
    int left = 0, right = 0;
    int currentSum = 0;
    int maxLength = -1;
    unordered_set<int> currentWindow;  // 用于检查是否包含 target

    while (right < n) {
        currentSum += nums[right];
        currentWindow.insert(nums[right]);

        // 如果当前和超过 K，缩小左边界
        while (currentSum > K && left <= right) {
            currentSum -= nums[left];
            // 如果 nums[left] 在窗口中只有一个，就从集合中移除
            if (currentWindow.count(nums[left])) {
                currentWindow.erase(nums[left]);
                for (int i = left + 1; i <= right; ++i) {
                    currentWindow.insert(nums[i]);
                }
            }
            ++left;
        }

        // 检查当前窗口是否满足条件（包含 target 且和不超过 K）
        if (currentWindow.count(target)) {
            maxLength = max(maxLength, right - left + 1);
        }

        ++right;
    }

    return maxLength;
}

// 测试示例
int main() {
    vector<int> nums = {1, 2, 3, 0, 4, 5, 5};
    int K = 7;
    int target = 3;

    int result = longestSubarrayWithTargetAndSumLimit(nums, K, target);
    cout << "输出: " << result << endl;

    return 0;
}
