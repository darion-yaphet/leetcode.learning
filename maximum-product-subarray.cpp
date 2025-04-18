//
// Created by Chenguang Wang on 2024/3/3.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }

    int maxProduct2(vector<int> &A) {
        int maxProd = 1, minProd = 1;
        int ans = INT_MIN;
        for (int n: A) {
            int a = n * maxProd;
            int b = n * minProd;
            maxProd = max({n, a, b});
            minProd = min({n, a, b});
            ans = max(ans, maxProd);
        }
        return ans;
    }

    int maxProduct3(vector<int>& nums) {
        if (nums.empty()) return 0; // 空数组直接返回 0

        // 初始化变量
        int maxProduct = nums[0]; // 当前最大乘积
        int minProduct = nums[0]; // 当前最小乘积
        int result = nums[0];     // 全局最大乘积

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            // 如果当前元素为负数，交换 maxProduct 和 minProduct
            if (num < 0) {
                swap(maxProduct, minProduct);
            }

            // 更新 maxProduct 和 minProduct
            maxProduct = max(num, maxProduct * num); // 当前最大乘积
            minProduct = min(num, minProduct * num); // 当前最小乘积

            // 更新全局最大乘积
            result = max(result, maxProduct);
        }
        return result;
    }
};