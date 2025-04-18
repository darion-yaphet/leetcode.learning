//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/valid-anagram

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int counters[26];
        int countert[26];
        for (int i = 0; i < s.size(); i++) {
            counters[s[i] - 'a']++;
            countert[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (counters[i] != countert[i]) {
                return false;
            }
        }

        return true;
    }
};
