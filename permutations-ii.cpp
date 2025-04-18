//
// Created by Chenguang Wang on 2024/1/23.
//

// https://leetcode.cn/problems/permutations-ii/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
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

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};