//
// Created by darion.yaphet on 2024/9/23.
//

// https://leetcode.cn/problems/trapping-rain-water/description/

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;

        for (int i = 0; i < height.size(); i++) {
            // 第一个柱子和最后一个柱子不接雨水
            if (i == 0 || i == height.size() - 1) {
                continue;
            }

            int rHeight = height[i];
            int lHeight = height[i];

            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight) {
                    rHeight = height[r];
                }
            }

            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) {
                    lHeight = height[l];
                }
            }

            int h = min(lHeight, rHeight) - height[i];
            if (h > 0) {
                sum += h;
            }
        }
        return sum;
    }
};