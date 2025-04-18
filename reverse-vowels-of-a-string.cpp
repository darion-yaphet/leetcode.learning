//
// Created by Chenguang Wang on 2024/2/16.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
            return vowels.find(ch) != string::npos;
        };

        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < n && !isVowel(s[left])) {
                ++left;
            }

            while (right > 0 && !isVowel(s[right])) {
                --right;
            }

            if (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }

        return s;
    }
};