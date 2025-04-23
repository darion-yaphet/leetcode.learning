//
// Created by darion.yaphet on 2025/4/23.
//

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
class Solution {
public:
    /**
    * 核心思想是：
    * 如果一个字符在整个字符串中出现次数少于 k，那么这个字符不可能出现在合法的子串中。
    * 因此，可以以这些字符为分隔符，将字符串分割成若干子串，递归处理每个子串。
     */
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

private:
    int helper(const string& s, int start, int end, int k) {
        // 如果子串的长度小于 k，则返回 0
        if (end - start < k) {
            return 0;
        }

        // 统计子串中每个字符出现的次数
        unordered_map<char, int> freq;
        for (int i = start; i < end; ++i) {
            freq[s[i]]++;
        }

        // 如果子串中某个字符出现的次数少于 k，则将子串分割成若干个子串，分别处理
        for (int i = start; i < end; ++i) {
            if (freq[s[i]] < k) {
                int j = i + 1;
                while (j < end && freq[s[j]] < k) {
                    ++j;
                }
                return max(helper(s, start, i, k), helper(s, j, end, k));
            }
        }

        return end - start;
    }
};

int main() {
    Solution sol;
    string s = "aaabb";
    int k = 3;
    cout << "Longest valid substring length: " << sol.longestSubstring(s, k) << endl;
    return 0;
}