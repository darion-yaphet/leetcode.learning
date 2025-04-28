//
// Created by Chenguang Wang on 2024/1/17.
//

// https://leetcode.cn/problems/merge-sorted-array/description/

#include <vector>

using namespace std;

// https://leetcode.cn/problems/merge-sorted-array/description/
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int p1 = 0, p2 = 0;
        int value = 0;
        int sorted[m + n];
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                value = nums2[p2++];
            } else if (p2 == n) {
                value = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                value = nums1[p1++];
            } else {
                value = nums2[p2++];
            }

            sorted[p1 + p2 - 1] = value;
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = sorted[i];
        }
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 定义三个指针
        int i = m - 1;      // 指向 nums1 中有效数据的最后一个元素
        int j = n - 1;      // 指向 nums2 的最后一个元素
        int k = m + n - 1;  // 指向 nums1 的最后一个位置

        // 从后向前遍历，将较大的元素放入 nums1 的末尾
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // 如果 nums2 中还有剩余元素，直接复制到 nums1 的前面
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // 如果 nums1 中还有剩余元素，无需处理，因为它们已经在正确的位置
    }
};
