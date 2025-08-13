//
// Created by darion.yaphet on 2025/7/1.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/arithmetic-slices/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        int count = 0;
        int length = 2; // 当前等差序列的长度，初始为两个元素

        for (int i = 2; i < n; ++i) {
            // 判断当前是否还保持等差
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                length++;
                if (length >= 3) {
                    count += length - 2; // 每增加一个元素，可以多出 length - 2 个新子数组
                }
            } else {
                length = 2; // 重新开始计算等差序列
            }
        }
        return count;
    }
};
