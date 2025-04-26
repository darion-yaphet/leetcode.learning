//
// Created by darion.yaphet on 2025/4/26.
//

// https://leetcode.cn/problems/ugly-number/
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 2 == 0) {
            n /= 2;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        while (n % 5 == 0) {
            n /= 5;
        }

        return n == 1;
    }
};
