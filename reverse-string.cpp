//
// Created by Chenguang Wang on 2024/2/16.
//

// https://leetcode.cn/problems/reverse-string/description/

#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;

            left += 1;
            right -= 1;
        }
    }
};