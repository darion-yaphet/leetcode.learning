//
// Created by Chenguang Wang on 2024/2/10.
//

// https://leetcode.cn/problems/product-of-array-except-self/description/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int length = nums.size();

        // L 和 R 分别表示左右两侧的乘积列表
        vector<int> L(length, 0), R(length, 0);
        vector<int> result(length);

        // L[i] 为索引 i 左侧所有元素的乘积
        // 对于索引为 '0' 的元素，因为左侧没有元素，所以 L[0] = 1
        L[0] = 1;
        for (int i = 1; i < length; i++) {
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] 为索引 i 右侧所有元素的乘积
        // 对于索引为 'length-1' 的元素，因为右侧没有元素，所以 R[length-1] = 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--) {
            R[i] = nums[i + 1] * R[i + 1];
        }

        // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
        for (int i = 0; i < length; i++) {
            result[i] = L[i] * R[i];
        }
        return result;
    }

    vector<int> productExceptSelf2(vector<int> &nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // 初始化 answer 数组为全 1

        // 第一次遍历：计算左侧乘积
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = leftProduct; // 当前位置的左侧乘积
            leftProduct *= nums[i]; // 更新左侧乘积
        }

        // 第二次遍历：计算右侧乘积，并更新 answer
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= rightProduct; // 当前位置的右侧乘积
            rightProduct *= nums[i]; // 更新右侧乘积
        }

        return answer;
    }
};
