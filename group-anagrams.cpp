//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/group-anagrams

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for (const string &str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        for (auto iter = map.begin(); iter != map.end(); iter++) {
            result.emplace_back(iter->second);
        }

        return result;
    }
};