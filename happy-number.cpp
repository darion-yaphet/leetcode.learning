//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/happy-number

#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }

        unordered_set<int> set;
        while (true) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }

            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};