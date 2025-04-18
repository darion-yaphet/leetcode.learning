//
// Created by Chenguang Wang on 2024/2/19.
//

// https://leetcode.cn/problems/valid-palindrome-ii/description/

#include <string>

using namespace std;

class Solution {
private:
    bool checkPalindrome(const string &s, int low, int high) {
        for (int i = low, j = high; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            if (s[low] == s[high]) {
                low += 1;
                high -= 1;
            } else {
                return checkPalindrome(s, low + 1, high) || checkPalindrome(s, low, high - 1);
            }
        }
        return true;
    }
};