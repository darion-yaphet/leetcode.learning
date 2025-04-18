//
// Created by Chenguang Wang on 2024/2/12.
//

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (const auto &c: s1) {
            need[c] += 1;
        }

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right += 1;

            if (need.count(c)) {
                window[c] += 1;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
        }

        while (right - left >= s1.size()) {
            if (valid == need.size()) {
                return true;
            }

            char d = s2[left];
            left += 1;

            if (need.count(d)) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
        return false;
    }
};