//
// Created by darion.yaphet on 2025/5/18.
//

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/complex-number-multiplication/
class Solution {
public:

    // sscanf 的作用是从字符串 str 中按照指定格式 format 提取数据。
    // 类似于 scanf，但不是从控制台读取，而是从字符串中提取。
    string complexNumberMultiply(string num1, string num2) {
        int a, b, c, d;

        // 解析 num1
        sscanf(num1.c_str(), "%d+%di", &a, &b);
        // 解析 num2
        sscanf(num2.c_str(), "%d+%di", &c, &d);

        // 计算实部和虚部
        int real = a * c - b * d;
        int imag = a * d + b * c;

        // 格式化输出
        ostringstream oss;
        oss << real << "+" << imag << "i";
        return oss.str();
    }
};
