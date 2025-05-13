//
// Created by darion.yaphet on 2025/5/13.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        // 结果最多有 m + n 位
        vector<int> result(n + m, 0);

        // 从个位开始相乘
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j + 1;

                // 累加到对应位置
                int sum = mul + result[p2];

                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }

        // 转换为字符串并去除前导零
        string res;
        for (int digit: result) {
            res.push_back(digit + '0');
        }

        // 去除前导零
        while (res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }

        return res;
    }
};
