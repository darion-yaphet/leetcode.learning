//
// Created by Chenguang Wang on 2024/2/1.
//

//https://leetcode.cn/problems/target-sum/description/

#include <vector>

using namespace std;

class Solution {
public:

    int count = 0;

    void backtrack(vector<int> &nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
        } else {
            backtrack(nums, target, index + 1, sum + nums[index]);
            backtrack(nums, target, index + 1, sum - nums[index]);
        }
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }
};