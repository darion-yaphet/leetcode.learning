//
// Created by Chenguang Wang on 2024/1/31.
//

#include <vector>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>> &grid) {
        int result = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < n; i++) {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }

        for (int j = 0; j < m; j++) {
            dfs(grid, j, 0);
            dfs(grid, j, n - 1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    result += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }

        if (grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};