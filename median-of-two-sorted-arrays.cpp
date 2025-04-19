//
// Created by darion.yaphet on 2025/4/19.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保 nums1 是较短的数组
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2); // 交换 nums1 和 nums2
        }

        int m = nums1.size(); // nums1 的长度
        int n = nums2.size(); // nums2 的长度

        int left = 0, right = m; // 在 nums1 上进行二分查找的范围
        int half_len = (m + n + 1) / 2; // 左半部分的元素个数

        while (left <= right) {
            int i = (left + right) / 2; // nums1 的划分点
            int j = half_len - i;       // nums2 的划分点

            // 边界条件处理
            int nums1_left_max = (i == 0) ? numeric_limits<int>::min() : nums1[i - 1];
            int nums1_right_min = (i == m) ? numeric_limits<int>::max() : nums1[i];
            int nums2_left_max = (j == 0) ? numeric_limits<int>::min() : nums2[j - 1];
            int nums2_right_min = (j == n) ? numeric_limits<int>::max() : nums2[j];

            // 检查是否满足划分条件
            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                // 找到正确的划分点
                if ((m + n) % 2 == 1) { // 总长度为奇数
                    return max(nums1_left_max, nums2_left_max);
                } else { // 总长度为偶数
                    return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2.0;
                }
            } else if (nums1_left_max > nums2_right_min) {
                // 划分点太靠右，向左移动
                right = i - 1;
            } else {
                // 划分点太靠左，向右移动
                left = i + 1;
            }
        }

        // 如果没有找到解（理论上不会发生）
        return 0.0;
    }
};