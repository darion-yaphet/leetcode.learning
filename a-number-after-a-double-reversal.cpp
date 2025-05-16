//
// Created by darion.yaphet on 2025/5/16.
//

// https://leetcode.cn/problems/a-number-after-a-double-reversal/
class Solution {
public:
    bool isSameAfterReversals(int num) {
        int rev1 = reverseNumber(num);
        int rev2 = reverseNumber(rev1);
        return rev2 == num;
    }

    int reverseNumber(int num) {
        int reversed = 0;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            reversed = reversed * 10 + digit;
        }
        return reversed;
    }
};
