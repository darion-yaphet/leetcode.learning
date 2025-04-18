//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/pascals-triangle/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> v;
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    v.push_back(1);
                } else {
                    v.push_back(result[i - 1][numRows - 1] + result[i - 1][numRows]);
                }
            }

            result.emplace_back(std::move(v));
        }

        return result;
    }

    vector<vector<int>> generate2(int numRows) {
        vector<vector<int>> triangle; // 存储杨辉三角的所有行

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // 初始化当前行，所有元素初始为 1

            // 填充中间元素（从第 2 行开始）
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // 将当前行加入结果
            triangle.push_back(row);
        }

        return triangle;
    }
};