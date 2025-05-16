//
// Created by darion.yaphet on 2024/9/20.
//

// https://leetcode.cn/problems/search-in-rotated-sorted-array/description/

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 每次将数组分为两部分 [left, mid] 和 [mid+1, right]，其中至少有一部分是有序的。
     *
     * 可以通过比较中间值 nums[mid] 与端点值来判断哪边是有序的：
     *
     * 如果 nums[left] <= nums[mid]，说明左边是有序的。
     * 否则右边是有序的。
     */
    int search(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return -1;
        }

        if (size == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // 左半部分是有序的
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 右半部分是有序的
                if (nums[mid] < target && target <= nums[size - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
