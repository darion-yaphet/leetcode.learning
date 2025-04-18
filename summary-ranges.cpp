//
// Created by Chenguang Wang on 2024/2/12.
//

// https://leetcode.cn/problems/summary-ranges/

#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result; // 存储结果区间
        if (nums.empty()) return result; // 特殊情况：空数组

        int start = nums[0]; // 当前区间起点
        int end = nums[0];   // 当前区间终点

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                // 如果当前数字与前一个数字连续，更新区间终点
                end = nums[i];
            } else {
                // 如果不连续，保存当前区间，并开启新区间
                if (start == end) {
                    result.push_back(to_string(start)); // 单个数字区间
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end)); // 连续区间
                }
                start = nums[i]; // 更新新区间的起点
                end = nums[i];   // 更新新区间的终点
            }
        }

        // 处理最后一个区间
        if (start == end) {
            result.push_back(to_string(start));
        } else {
            result.push_back(to_string(start) + "->" + to_string(end));
        }

        return result;
    }
};