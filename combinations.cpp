//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/combinations/

#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int index = startIndex; index <= n; index++) {
            path.push_back(index);
            backtracking(n, k, index + 1);
            path.pop_back();
        }
    }


public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};