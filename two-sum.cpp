//
// Created by Chenguang Wang on 2024/1/18.
//

#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int32_t, int32_t> map;
        for (int index = 0; index < nums.size(); index++) {
            int value = target - nums[index];
            if (map.find(value) != map.end()) {
                return {map[value], index};
            }
            map[nums[index]] = index;
        }

        return {};
    }
};
