//
// Created by darion.yaphet on 2025/5/30.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/sort-array-by-parity/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;
            } else if (nums[right] % 2 == 1) {
                right--;
            } else {
                swap(nums[left], nums[right]);
            }
        }
        return nums;
    }
};
