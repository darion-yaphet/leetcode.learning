//
// Created by Chenguang Wang on 2024/1/27.
//

// https://leetcode.cn/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int result;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mid * mid;
            if (value <= x) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};