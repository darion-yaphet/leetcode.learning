//
// Created by Chenguang Wang on 2024/1/22.
//

//https://leetcode.cn/problems/word-search/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs{{0,  1},
                             {0,  -1},
                             {1,  0},
                             {-1, 0}};
    vector<vector<int>> visited;
    int cnt = 0;

    bool exist(vector<vector<char>> &board, string word) {
        int n = board.size(), m = board[0].size();
        visited = vector<vector<int >>(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                //if(board[i][j] != word[0])  continue;//第一位就不等
                if (dfs(board, word, i, j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int x, int y) {
        //当前字符不同
        if (board[x][y] != word[cnt]) {
            return false;
        }

        //最后一个字符相同
        if (cnt == word.size() - 1) {
            return true;
        }
        
        ++cnt;
        visited[x][y] = 1;
        for (const auto &dir: dirs) {
            if (x + dir[0] < 0 || x + dir[0] >= board.size() || y + dir[1] < 0 || y + dir[1] >= board[0].size() ||
                visited[x + dir[0]][y + dir[1]])
                continue;
            if (dfs(board, word, x + dir[0], y + dir[1])) return true;
        }
        --cnt;
        visited[x][y] = 0;
        return false;
    }
};
