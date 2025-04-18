//
// Created by darion.yaphet on 2024/10/26.
//

// https://leetcode.cn/problems/powx-n/description/

class Solution {
private:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }

        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
