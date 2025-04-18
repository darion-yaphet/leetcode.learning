//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long int target = x;
        long long int value = 0;
        while (x / 10 != 0) {
            int n = x % 10;
            value *= 10;
            value += n;

            x /= 10;
        }

        return target == value;
    }
};