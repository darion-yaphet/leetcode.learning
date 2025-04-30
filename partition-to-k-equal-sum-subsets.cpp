//
// Created by darion.yaphet on 2025/4/30.
//
#include <vector>

using namespace std;

// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/
class Solution {
public:
    // 排序数组 nums（从大到小），以便优先尝试较大的数字，减少不必要的递归分支。
    // 使用一个辅助数组 used 记录哪些数字已经被使用。
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int totalSum = 0;
        for (int num: nums) {
            totalSum += num;
        }

        // 如果总和不能被 k 整除，直接返回 false
        if (totalSum % k != 0) {
            return false;
        }

        int target = totalSum / k; // 目标子集和
        vector used(nums.size(), false); // 标记数组
        sort(nums.rbegin(), nums.rend()); // 从大到小排序，优化回溯效率

        return backtrack(nums, used, 0, 0, target, k);
    }


    bool backtrack(vector<int> &nums, vector<bool> &used, int start, int currentSum, int target, int k) {
        // 如果所有子集都满足条件，返回 true
        if (k == 0) {
            return true;
        }

        // 如果当前子集的和等于目标值，尝试填充下一个子集
        if (currentSum == target) {
            return backtrack(nums, used, 0, 0, target, k - 1);
        }

        // 尝试将剩余的数字放入当前子集
        for (int i = start; i < nums.size(); ++i) {
            // 剪枝
            if (used[i] || currentSum + nums[i] > target) {
                continue;
            }

            // 标记当前数字已使用
            used[i] = true;
            if (backtrack(nums, used, i + 1, currentSum + nums[i], target, k)) {
                return true;
            }

            // 回溯：取消标记
            used[i] = false;

            // 如果当前数字无法放入任何子集，则提前终止
            if (currentSum == 0) {
                break;
            }
        }
        return false;
    }
};
