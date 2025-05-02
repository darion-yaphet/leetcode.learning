//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/maximum-subarray/description/

#include <vector>

using namespace std;

/**
 * 如果当前子数组的和变成负数了，那么它对后续子数组的贡献就是负面的，
 * 应该放弃当前子数组并从下一个元素重新开始计算。
 */
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];

        for (int i = 0; i < n; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }

        int result = INT_MIN;
        for (int i = 0; i < n; i++) {
            result = max(result, dp[i]);
        }
        return result;
    }

    int maxSubArray2(vector<int> &nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) {
                result = count;
            }

            if (count < 0) {
                count = 0;
            }
        }
        return result;
    }

    // Kadane's Algorithm
    int maxSubArray3(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // 初始化变量
        int currentSum = nums[0]; // 当前子数组的和
        int maxSum = nums[0];     // 全局最大子数组和

        // 遍历数组
        for (int i = 1; i < n; ++i) {
            // 更新当前子数组的和
            currentSum = max(nums[i], currentSum + nums[i]);
            // 更新全局最大子数组和
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};