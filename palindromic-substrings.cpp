//
// Created by Chenguang Wang on 2024/2/25.
//

#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        int result = 0;
        for (int i = 0; i < 2 * size - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < size && s[l] == s[r]) {
                l -= 1;
                r += 1;
                result += 1;
            }
        }
        return result;
    }

    int countSubstrings2(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            result += extend(s, i, i, s.size());
            result += extend(s, i, i + 1, s.size());
        }
        return result;
    }

    int extend(const string &s, int i, int j, int n) {
        int result = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            result++;
        }
        return result;
    }
};