//
// Created by darion.yaphet on 2025/4/19.
//

#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/number-of-islands/

class Solution {
public:
    /**
     * 遍历整个二维网格。
     * 当遇到一个未访问过的陆地 '1' 时，启动一次 DFS，将该陆地及其所有相连的陆地标记为已访问
     * （通过将其置为 '0' 或使用辅助数组标记）。
     * 每次启动 DFS 时，岛屿计数加 1。
     * 最终返回岛屿的总数。
     *
     * @param grid
     * @return
     */
    int numIslands(vector<vector<char>>& grid) {
        // 如果网格为空，直接返回 0
        if (grid.empty()) {
            return 0;
        }

        int rows = grid.size();       // 网格行数
        int cols = grid[0].size();    // 网格列数
        int islandCount = 0;          // 岛屿计数

        // 遍历整个网格
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // 如果发现一块陆地 '1'
                if (grid[i][j] == '1') {
                    ++islandCount;   // 发现一个新岛屿
                    dfs(grid, i, j); // 使用 DFS 将其相连的陆地全部标记为已访问
                }
            }
        }

        return islandCount;
    }

    // 深度优先搜索函数
    void dfs(vector<vector<char>>& grid, int row, int col) {
        // 边界检查：如果越界或当前位置是水 '0'，直接返回
        if (row < 0 || col < 0 ||
            row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == '0') {
            return;
        }

        // 将当前陆地标记为已访问（置为 '0'）
        grid[row][col] = '0';

        // 对四个方向进行递归搜索
        dfs(grid, row - 1, col); // 上
        dfs(grid, row + 1, col); // 下
        dfs(grid, row, col - 1); // 左
        dfs(grid, row, col + 1); // 右
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    cout << "Number of Islands: " << solution.numIslands(grid) << endl;
    return 0;
}