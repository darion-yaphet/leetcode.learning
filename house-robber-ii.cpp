//
// Created by Chenguang Wang on 2024/2/1.
//

// https://leetcode.cn/problems/house-robber-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        return max(robRange(nums, 0, size - 2),
                   robRange(nums, 1, size - 1));
    }

    int robRange(vector<int> &nums, int start, int end) {
        int n = nums.size();
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp_i = 0;
        for (int i = end; i >= start; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};