//
// Created by Chenguang Wang on 2024/2/19.
//

// https://leetcode.cn/problems/remove-k-digits/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    //去除前导0
    string handle(string num) {
        int i = 0;
        while (num[i] == '0') {
            i++;
        }

        if (i == num.size()) {
            return "0";
        }
        return num.substr(i);
    }

    string removeKdigits2(string num, int k) {
        for (int i = 0; i < num.size() && k;) {
            if (i == num.size() - 1 || num[i] > num[i + 1]) {
                num.erase(i, 1), i == 0 ? i : i--, k--;
            } else {
                i++;
            }
        }
        return handle(num);
    }

    string removeKdigits(string num, int k) {
        vector<char> stack;
        for (auto &digit: num) {
            while (!stack.empty() && stack.back() > digit && k) {
                stack.pop_back();
                k -= 1;
            }
            stack.push_back(digit);
        }

        for (; k > 0; --k) {
            stack.pop_back();
        }

        string result;
        bool isLeadingZero = true;
        for (auto &digit: stack) {
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            result += digit;
        }
        return result.empty() ? "0" : result;
    }
};