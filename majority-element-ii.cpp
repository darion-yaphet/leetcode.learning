//
// Created by Chenguang Wang on 2024/2/12.
//

// https://leetcode.cn/problems/majority-element-ii

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> map;
        for (const auto &num: nums) {
            map[num]++;
        }

        for (const auto &[key, value]: map) {
            if (value > n / 3) {
                result.push_back(value);
            }
        }
        return result;
    }
};