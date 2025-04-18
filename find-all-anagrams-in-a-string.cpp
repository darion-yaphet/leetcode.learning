//
// Created by Chenguang Wang on 2024/2/12.
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (const auto &c: p) {
            need[c] += 1;
        }

        int left = 0, right = 0;
        int valid = 0;
        vector<int> result;
        while (right < s.size()) {
            char c = s[right];
            right += 1;

            if (need.count(c)) {
                window[c] += 1;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    result.push_back(left);
                }

                char d = s[left];
                left++;

                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return result;
    }
};