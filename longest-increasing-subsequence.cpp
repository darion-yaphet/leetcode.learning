//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/longest-increasing-subsequence/description/

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> dp(n, 1); // dp[i] 表示以 nums[i] 结尾的最长递增子序列长度

        // 对于所有 j<i 且 nums[j]<nums[i]
        // dp[i]=max(dp[j]+1)
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); // 返回 dp 数组中的最大值
    }
};
