//
// Created by Chenguang Wang on 2024/1/28.
//

#include <vector>

// https://leetcode.cn/problems/squares-of-a-sorted-array/

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int p = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[p--] = nums[j] * nums[j];
                j--;
            } else {
                result[p--] = nums[i] * nums[i];
                i++;
            }
        }

        return result;
    }

    vector<int> sortedSquares2(vector<int> &nums) {
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int p = nums.size() - 1;

        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                result[p--] = nums[right] * nums[right];
                right -= 1;
            } else {
                result[p--] = nums[left] * nums[left];
                left += 1;
            }
        }
        return result;
    }
};
