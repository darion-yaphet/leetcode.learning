//
// Created by darion.yaphet on 2024/10/17.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) { // 遍历物品
            for (int j = 1; j <= target; j++) { // 遍历背包容量
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size() - 1][target];
    }
};