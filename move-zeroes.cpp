//
// Created by Chenguang Wang on 2024/2/16.
//

// https://leetcode.cn/problems/move-zeroes/

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.empty()) {
            return;
        }

        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};