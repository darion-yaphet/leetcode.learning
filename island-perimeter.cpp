//
// Created by Chenguang Wang on 2024/1/31.
//

// https://leetcode.cn/problems/island-perimeter/description/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if (tx < 0 || tx >= n ||
                            ty < 0 || ty >= m ||
                            !grid[tx][ty]) {
                            cnt += 1;
                        }
                    }
                    ans += cnt;
                }
            }
        }
        return ans;
    }

    int islandPerimeter2(vector<vector<int>>& grid) {
        int rows = grid.size();       // 网格行数

        // 特殊情况：空网格
        if (rows == 0) {
            return 0;
        }

        int cols = grid[0].size();    // 网格列数
        int perimeter = 0;            // 岛屿周长

        // 遍历网格中的每个单元格
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) { // 如果是陆地
                    perimeter += 4;   // 每块陆地初始贡献 4 条边

                    // 检查上方是否是陆地
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 2; // 减去共享边
                    }

                    // 检查左方是否是陆地
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 2; // 减去共享边
                    }
                }
            }
        }

        return perimeter;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    Solution solution;
    cout << "Island Perimeter: " << solution.islandPerimeter(grid) << endl;

    return 0;
}