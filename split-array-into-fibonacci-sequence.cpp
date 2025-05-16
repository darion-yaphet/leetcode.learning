//
// Created by darion.yaphet on 2025/5/16.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/split-array-into-fibonacci-sequence/
class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> path;
        backtrack(num, 0, path);
        return path;
    }

    bool backtrack(const string &num, int start, vector<int> &path) {
        if (start == num.size()) {
            return path.size() >= 3;
        }

        // 用 long long 避免溢出
        long long curVal = 0;
        for (int i = start; i < num.size(); ++i) {
            // 剪枝：前导零
            if (num[start] == '0' && i > start) {
                break;
            }

            // 取当前子串对应的数值
            curVal = curVal * 10 + (num[i] - '0');

            // 剪枝：超出 int 范围
            if (curVal > INT_MAX) {
                break;
            }

            int len = path.size();

            // 如果路径不足两个数，可以直接加入
            if (len < 2) {
                path.push_back(curVal);
                if (backtrack(num, i + 1, path)) {
                    return true;
                }

                path.pop_back();
            } else {
                // 检查是否符合斐波那契规则
                if ((long long) path[len - 1] + (long long) path[len - 2] == curVal) {
                    path.push_back(curVal);
                    if (backtrack(num, i + 1, path)) {
                        return true;
                    }

                    path.pop_back();
                }
            }
        }
        return false;
    }
};
