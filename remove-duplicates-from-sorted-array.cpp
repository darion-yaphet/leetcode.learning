//
// Created by Chenguang Wang on 2024/1/18.
//
#include <vector>

using namespace std;

// https://leetcode.cn/problems/remove-duplicates-from-sorted-array
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }

    int removeDuplicates2(vector<int> &nums) {
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {
                nums[index++] = nums[i - 1];
            }
        }
        return index;
    }
};