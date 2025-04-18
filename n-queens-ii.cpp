//
// Created by Chenguang Wang on 2024/1/23.
//

// https://leetcode.cn/problems/n-queens-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    int counter = 0;

    bool isValid(vector<string> board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void backtracking(vector<string> board, int row) {
        if (row == board.size()) {
            counter += 1;
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col)) {
                continue;
            }

            board[row][col] = 'Q';
            backtracking(board, row + 1);
            board[row][col] = '.';
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtracking(board, 0);
        return counter;
    }
};