//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/permutations/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

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

    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> track;
        backtracking(nums, track);
        return result;
    }
};