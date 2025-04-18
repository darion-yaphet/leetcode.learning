//
// Created by Chenguang Wang on 2024/1/21.
//

//https://leetcode.cn/problems/combination-sum-iii/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (sum > targetSum) {
            return;
        }

        if (k == path.size()) {
            if (sum == targetSum) {
                result.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, startIndex++);
            sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return result;
    }
};