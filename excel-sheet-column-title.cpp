//
// Created by darion.yaphet on 2025/4/27.
//

#include <string>

using namespace std;

// https://leetcode.cn/problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = ""; // 存储最终结果

        while (columnNumber > 0) {
            // 处理当前位的字母
            columnNumber--; // 因为 Excel 的列编号从 1 开始，减去 1 转换为从 0 开始
            char currentChar = 'A' + (columnNumber % 26); // 计算当前字母
            result = currentChar + result; // 插入到结果字符串的前面
            columnNumber /= 26; // 更新 columnNumber，继续处理更高一位
        }

        return result;
    }
};
