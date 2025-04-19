//
// Created by Chenguang Wang on 2024/1/24.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        int result = size;
        while (left <= right) {
            int middle = (left + right) / 2;

            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                result = middle;
                right = middle - 1;
            }
        }

        return result;
    }
};