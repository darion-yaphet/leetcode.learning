//
// Created by darion.yaphet on 2025/4/21.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        // dp[i]: 以 nums[i] 结尾的最长递增子序列的长度
        vector<int> dp(n, 1);
        // count[i]: 以 nums[i] 结尾的最长递增子序列的个数
        vector<int> count(n, 1);

        int maxLength = 1; // 记录最长递增子序列的长度
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // 更新计数
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j]; // 累加计数
                    }
                }
            }
            maxLength = max(maxLength, dp[i]); // 更新最大长度
        }
        // 统计最长递增子序列的总个数
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLength) {
                result += count[i];
            }
        }
        return result;
    }
};
