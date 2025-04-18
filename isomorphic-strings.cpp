//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/isomorphic-strings

#include <string>
#include <unordered_map>

using namespace std;

// 使用两个map 保存 s[i] 到 t[j] 和 t[j] 到 s[i] 的映射关系，如果发现对应不上，立刻返回 false
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            // map1保存s[i] 到 t[j]的映射
            if (map1.find(s[i]) == map1.end()) {
                map1[s[i]] = t[j];
            }

            // map2保存t[j] 到 s[i]的映射
            if (map2.find(t[j]) == map2.end()) {
                map2[t[j]] = s[i];
            }

            // 发现映射 对应不上，立刻返回false
            if (map1[s[i]] != t[j] || map2[t[j]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};