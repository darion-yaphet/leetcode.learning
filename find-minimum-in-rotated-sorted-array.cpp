//
// Created by darion.yaphet on 2024/9/19.
//

// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            } else {
                low = pivot + 1;
            }
        }
        return nums[low];
    }
};