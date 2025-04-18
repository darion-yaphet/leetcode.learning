//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/length-of-last-word/description/

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto position = s.find(" ");
        int start = 0;
        string token;
        while (position != std::string::npos) {
            token = s.substr(start, position - start);
            start = position + 1;
            position = s.find(" ", start);
        }
        return token.size();
    }

    int lengthOfLastWord2(string s) {
        int index = s.size() - 1;
        while (s[index] == ' ') {
            index -= 1;
        }

        int length = 0;
        while (index >= 0 && s[index] != ' ') {
            length += 1;
            index -= 1;
        }
        return length;
    }
};