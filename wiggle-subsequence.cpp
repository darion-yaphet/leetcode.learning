//
// Created by Chenguang Wang on 2024/2/4.
//

// https://leetcode.cn/problems/wiggle-subsequence/description/

#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1; // 记录峰值个数，序列默认序列最右边有一个峰值

        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
            }
            preDiff = curDiff;
        }

        return result;
    }
};