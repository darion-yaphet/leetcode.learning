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
};