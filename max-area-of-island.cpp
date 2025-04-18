//
// Created by Chenguang Wang on 2024/1/31.
//

// https://leetcode.cn/problems/max-area-of-island/

#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int result = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result = max(result, dfs(grid, i, j));
                }
            }
        }
        return result;
    }

    int dfs(vector<vector<int>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }

        if (grid[i][j] == 0) {
            // 已经是海水了
            return 0;
        }

        // 将 (i, j) 变成海水
        grid[i][j] = 0;

        return dfs(grid, i + 1, j)
               + dfs(grid, i, j + 1)
               + dfs(grid, i - 1, j)
               + dfs(grid, i, j - 1) + 1;
    }
};