//
// Created by Chenguang Wang on 2024/1/17.
//

// https://leetcode.cn/problems/remove-element/

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int size = nums.size();
        int left = 0;
        for (int right = 0; right < size; right++) {
            if (nums[right] != val) {
                nums[left++] = nums[right];
            }
        }
        return left;
    }
};