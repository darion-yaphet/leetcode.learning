//
// Created by Chenguang Wang on 2024/1/28.
//

//https://leetcode.cn/problems/subsets-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int start) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};