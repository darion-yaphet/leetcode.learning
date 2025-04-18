//
// Created by Chenguang Wang on 2024/3/3.
//

// https://leetcode.cn/problems/combination-sum-iv/

#include <vector>

using namespace std;

class Solution {
private:
    int counter = 0;

    void backtracking(vector<int> &nums, int target, int sum) {
        if (sum == target) {
            counter += 1;
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > target) {
                continue;
            }
            sum += nums[i];
            backtracking(nums, target, sum);
            sum -= nums[i];
        }
    }

public:
    int combinationSum4(vector<int> &nums, int target) {
        backtracking(nums, target, 0);
        return counter;
    }

    int combinationSum42(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) { // 遍历背包
            for (int j = 0; j < nums.size(); j++) { // 遍历物品
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};