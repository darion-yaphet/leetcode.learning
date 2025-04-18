//
// Created by Chenguang Wang on 2024/1/31.
//
#include <vector>

using namespace std;

// https://leetcode.cn/problems/sudoku-solver/description/
// 思路：
// 1. 尝试：尝试在当前位置放 1~9 的数字。
// 2. 剪枝：
//      1）如果当前数字不合法，则跳过。
//      2）如果已经遍历完数独，则返回 true。
// 3. 状态：当前位置放了数字 n，则下一位为 (i + 1, j + 1)。
// 4. 结束：找到一个可行解，返回 true。
// 5. 递归：
//      1）如果 (i, j) 位置放了数字，则继续下一位
//      2）如果 (i, j) 位置没有数字，则尝试 1~9 的数字。
// 6. 回溯：
//      1）如果 (i, j) 位置放了数字，则继续下一位
//      2）如果 (i, j) 位置没有数字，则尝试 1~9 的数字。
//      3）如果尝试了 1~9 的数字，没有找到可行解，则返回 false。
//      4）如果找到一个可行解，则返回 true。

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>> &board, int i, int j) {
        int m = 9, n = 9;
        if (j == n) {
            // 穷举到最后一列的话就换到下一行重新开始。
            return backtrack(board, i + 1, 0);
        }

        if (i == m) {
            // 找到一个可行解，触发 base case
            return true;
        }

        if (board[i][j] != '.') {
            // 如果有预设数字，不用我们穷举
            return backtrack(board, i, j + 1);
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            // 如果遇到不合法的数字，就跳过
            if (!isValid(board, i, j, ch)) {
                continue;
            }

            board[i][j] = ch;
            // 如果找到一个可行解，立即结束
            if (backtrack(board, i, j + 1)) {
                return true;
            }

            board[i][j] = '.';
        }
        // 穷举完 1~9，依然没有找到可行解，此路不通
        return false;
    }

    // 判断 board[r][c] 是否可以填入 n
    bool isValid(vector<vector<char>> board, int r, int c, char n) {
        for (int i = 0; i < 9; i++) {
            // 判断行是否存在重复
            if (board[r][i] == n) return false;
            // 判断列是否存在重复
            if (board[i][c] == n) return false;
            // 判断 3 x 3 方框是否存在重复
            if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == n)
                return false;
        }
        return true;
    }
};