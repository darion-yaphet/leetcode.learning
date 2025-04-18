//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/rotate-array/description/

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        vector<int> result;
        for (int i = length - k; i < length; i++) {
            result.push_back(nums[i]);
        }

        for (int i = 0; i <= k; i++) {
            result.push_back(nums[i]);
        }

        for (int i = 0; i < length; i++) {
            nums[i] = result[i];
        }
    }

    void rotate2(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i) {
            newArr[(i + k) % n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }

};