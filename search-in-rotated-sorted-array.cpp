//
// Created by darion.yaphet on 2024/9/20.
//

// https://leetcode.cn/problems/search-in-rotated-sorted-array/description/

#include <vector>

using namespace std;

class Solution {
public:
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

            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
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
