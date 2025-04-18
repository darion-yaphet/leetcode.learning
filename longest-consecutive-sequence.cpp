//
// Created by Chenguang Wang on 2024/2/22.
//

// https://leetcode.cn/problems/longest-consecutive-sequence/description/

#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int result = 1;
        int counter = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 1) {
                counter += 1;
                result = max(result, counter);
            } else if (nums[i] - nums[i - 1] == 0) {
                // skip
            } else {
                counter = 1;
            }
        }
        return result;
    }
};