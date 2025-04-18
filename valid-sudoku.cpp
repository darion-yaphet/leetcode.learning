//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/valid-sudoku/description/
// 思路：
// 1. 遍历整个棋盘，对于每个格子，如果格子不为空，则将格子值减1，并记录在行、列、子矩阵中。
// 2. 如果某个值出现次数大于1，则返回false。
// 3. 如果遍历完整个棋盘后没有返回false，则返回true。

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int rows[9][9];
        int columns[9][9];
        int subboxes[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subboxes, 0, sizeof(subboxes));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i / 3][j / 3][index]++;
                    if (rows[i][index] > 1 ||
                        columns[j][index] > 1 ||
                        subboxes[i / 3][j / 3][index] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};