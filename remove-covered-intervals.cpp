//
// Created by darion.yaphet on 2025/5/12.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/remove-covered-intervals/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int> > &intervals) {
        // 按起点升序排列，如果起点相同，则按终点降序排列
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 // 起点相同，按终点降序
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }

                 return a[0] < b[0]; // 起点升序
             });

        int count = 0; // 记录未被覆盖的区间数量
        int maxEnd = 0; // 当前最大终点值

        for (const auto &interval: intervals) {
            int start = interval[0], end = interval[1];
            if (end > maxEnd) {
                // 如果当前区间的终点大于最大终点值，则它不会被覆盖
                ++count;
                maxEnd = end; // 更新最大终点值
            }
            // 否则跳过（被覆盖）
        }

        return count;
    }
};
