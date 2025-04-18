//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/majority-element

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        int index = nums.size() / 2;
        return nums[index];
    }
};