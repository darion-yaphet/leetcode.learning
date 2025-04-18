//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/combination-sum/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int index) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};