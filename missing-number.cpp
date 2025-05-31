//
// Created by darion.yaphet on 2025/5/31.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += i;
            sum -= nums[i];
        }

        return nums.size() + sum;
    }
};
