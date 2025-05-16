//
// Created by Chenguang Wang on 2024/1/23.
//

// https://leetcode.cn/problems/add-binary/

#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addBinary2(string a, string b) {
        string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            // 只有当字符是 '1' 时才加 1
            if (i >= 0 && a[i] == '1') {
                sum += 1;
            }

            if (j >= 0 && b[j] == '1') {
                sum += 1;
            }

            result.push_back((sum % 2) == 1 ? '1' : '0');
            // 更新进位
            carry = sum / 2;

            --i;
            --j;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
