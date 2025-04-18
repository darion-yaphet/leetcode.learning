//
// Created by Chenguang Wang on 2024/1/28.
//

//https://leetcode.cn/problems/subsets/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &nums, int start) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        backtracking(nums, 0);
        return result;
    }
};
