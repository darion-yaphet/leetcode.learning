//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/ransom-note/description/

#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) {
            return false;
        }

        int counter[26] = {0};
        for (char c: magazine) {
            counter[c - 'a']++;
        }

        for (char c: ransomNote) {
            int index = c - 'a';
            counter[index]--;
            if (counter[index] < 0) {
                return false;
            }
        }
        return true;
    }
};