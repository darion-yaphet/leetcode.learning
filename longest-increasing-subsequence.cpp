//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/longest-increasing-subsequence/description/

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int size = nums.size();
        int dp[size];
        for (int i = 0; i < size; i++) {
            dp[i] = 1;
        }

        int result;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], nums[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};