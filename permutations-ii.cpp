//
// Created by Chenguang Wang on 2024/1/23.
//

// https://leetcode.cn/problems/permutations-ii/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;

    void backtracking(vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            result.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }

    void backtrack2(vector<int> &nums,
                    vector<bool> &used,
                    vector<int> &current,
                    vector<vector<int> > &result) {
        // 如果当前排列的长度等于 nums 的长度，则记录结果
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // 遍历候选数字
        for (int i = 0; i < nums.size(); ++i) {
            // 跳过已使用的数字
            if (used[i]) {
                continue;
            }

            // 跳过重复数字（需要保证前一个相同的数字已被使用）
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            // 标记当前数字已使用
            used[i] = true;
            current.push_back(nums[i]);

            // 递归处理下一个数字
            backtrack2(nums, used, current, result);

            // 回溯：移除最后一个数字并标记为未使用
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int> > permuteUnique2(vector<int> &nums) {
        vector<vector<int> > result; // 存储所有排列
        vector<int> current; // 当前排列
        vector<bool> used(nums.size(), false); // 标记数组，记录哪些数字已被使用

        // 对数组排序，使相同的数字相邻
        sort(nums.begin(), nums.end());

        // 调用回溯函数
        backtrack2(nums, used, current, result);
        return result;
    }
};
