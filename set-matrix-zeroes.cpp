//
// Created by Chenguang Wang on 2024/2/7.
//

// https://leetcode.cn/problems/set-matrix-zeroes/description/

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool rowZero = false; // 第一行是否要置零
        bool colZero = false; // 第一列是否要置零

        // 检查第一行是否有 0
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                rowZero = true;
                break;
            }
        }

        // 检查第一列是否有 0
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }

        // 用第一行和第一列作为标记
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 根据标记将对应行/列置零
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }

        // 处理第一行和第一列
        if (rowZero) {
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }

        if (colZero) {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
    }
};
