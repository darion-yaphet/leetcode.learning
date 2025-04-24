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

    /**
     * 使用两个指针 left 和 right 分别从数组的两端向中间移动。
     *
     * 维护两个变量 maxLeft 和 maxRight，分别表示从左到右和从右到左的最大高度。
     *
     * 每次比较 height[left] 和 height[right]：
     * 如果 height[left] <= height[right]，说明左侧的柱子较低，决定当前水位的是 maxLeft。
     * 如果 height[left] < maxLeft，则可以接水，水量为 maxLeft - height[left]。
     * 否则更新 maxLeft，移动左指针 left++。
     *
     * 如果 height[left] > height[right]，说明右侧的柱子较低，决定当前水位的是 maxRight。
     * 如果 height[right] < maxRight，则可以接水，水量为 maxRight - height[right]。
     * 否则更新 maxRight，移动右指针 right--。
     */
    int trap2(vector<int> &height) {
        // 如果数组为空，直接返回 0
        if (height.empty()) {
            return 0;
        }

        int left = 0, right = height.size() - 1; // 左右指针
        int maxLeft = 0, maxRight = 0; // 左右最大高度
        int totalWater = 0; // 接雨水的总量

        while (left < right) {
            if (height[left] <= height[right]) {
                // 左侧柱子较低，决定水位的是 maxLeft
                if (height[left] >= maxLeft) {
                    maxLeft = height[left]; // 更新左侧最大高度
                } else {
                    totalWater += maxLeft - height[left]; // 累计接水
                }
                ++left; // 移动左指针
            } else {
                // 右侧柱子较低，决定水位的是 maxRight
                if (height[right] >= maxRight) {
                    maxRight = height[right]; // 更新右侧最大高度
                } else {
                    totalWater += maxRight - height[right]; // 累计接水
                }
                --right; // 移动右指针
            }
        }

        return totalWater;
    }
};
