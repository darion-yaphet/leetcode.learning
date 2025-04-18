//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int slow = 2, fast = 2;
        for (; fast < n; fast++) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};