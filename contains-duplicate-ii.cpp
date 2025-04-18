//
// Created by Chenguang Wang on 2024/1/21.
//

// https://leetcode.cn/problems/contains-duplicate-ii

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int index = 0; index < nums.size(); index++) {
            if (map.find(nums[index]) == map.end()) {
                map[nums[index]] = index;
            } else {
                if (k >= abs(index - map[nums[index]])) {
                    return true;
                } else {
                    map[nums[index]] = index;
                }
            }
        }
        return false;
    }
};