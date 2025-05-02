//
// Created by Chenguang Wang on 2024/2/8.
//

// https://leetcode.cn/problems/pascals-triangle-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                result[j] += result[j - 1];
            }
        }
        return result;
    }

    vector<int> getRow2(int rowIndex) {
        vector<int> row(rowIndex + 1, 0); // 初始化一个大小为 rowIndex+1 的数组
        row[0] = 1; // 第一个元素始终为 1

        for (int i = 1; i <= rowIndex; i++) {
            // 从右向左更新当前行的值
            for (int j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};
