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

    // 先对整个数组反转，再分别对前 k 个元素和剩余的 n-k 个元素进行反转。
    void reverseArray(vector<int> &nums, int start, int end) {
        while (start < end) {
            std::swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate3(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n; // 确保 k 在数组长度范围内

        // 第一次反转：整个数组
        reverseArray(nums, 0, n - 1);

        // 第二次反转：前 k 个元素
        reverseArray(nums, 0, k - 1);

        // 第三次反转：剩余的 n-k 个元素
        reverseArray(nums, k, n - 1);
    }
};
