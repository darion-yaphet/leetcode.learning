//
// Created by Chenguang Wang on 2024/1/17.
//

// https://leetcode.cn/problems/merge-sorted-array/description/

#include <vector>

using namespace std;

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
};
