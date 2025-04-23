//
// Created by darion.yaphet on 2025/4/21.
//

#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/
class Solution {
public:
    int longestSubsequence(std::vector<int>& arr, int difference) {
        // 哈希表 dp[x] 表示以 x 为结尾的等差子序列的长度
        unordered_map<int, int> dp;
        int maxLength = 0;

        // 遍历数组
        for (int x : arr) {
            // 计算前一个元素 prev = x - difference
            int prev = x - difference;

            // 如果 prev 存在于 dp 中，则更新 dp[x]
            if (dp.find(prev) != dp.end()) {
                    dp[x] = dp[prev] + 1;
            } else {
                // 否则初始化 dp[x] = 1
                dp[x] = 1;
            }

            // 更新最大长度
            maxLength = max(maxLength, dp[x]);
        }

        return maxLength;
    }
};