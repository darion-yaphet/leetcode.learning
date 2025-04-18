//
// Created by Chenguang Wang on 2024/2/19.
//

// https://leetcode.cn/problems/array-partition/description/

#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        int result = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2) {
            result += nums[i];
        }
        return result;
    }
};