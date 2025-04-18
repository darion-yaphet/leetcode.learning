//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/maximum-subarray/description/

#include <vector>

using namespace std;

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
};