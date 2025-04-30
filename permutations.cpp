//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/permutations/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > result;

    void backtracking(vector<int> &nums, vector<int> track) {
        if (track.size() == nums.size()) {
            result.emplace_back(track);
            return;
        }

        for (int index = 0; index < nums.size(); index++) {
            if (std::find(track.begin(), track.end(), nums[index]) != track.end()) {
                continue;
            }

            track.emplace_back(nums[index]);
            backtracking(nums, track);
            track.pop_back();
        }
    }

    vector<vector<int> > permute(vector<int> &nums) {
        vector<int> track;
        backtracking(nums, track);
        return result;
    }


    vector<vector<int> > permute2(vector<int> &nums) {
        vector<vector<int> > result; // 存储所有排列
        vector<int> current; // 当前排列
        vector<bool> used(nums.size(), false); // 标记数组，记录哪些数字已被使用
        backtrack2(nums, used, current, result);
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
            if (used[i]) {
                continue;
            }

            // 如果当前数字未被使用
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
};
