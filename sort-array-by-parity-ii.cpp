//
// Created by darion.yaphet on 2025/5/30.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/sort-array-by-parity-ii/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n);

        int evenIndex = 0; // 偶数位置
        int oddIndex = 1; // 奇数位置

        for (int num: nums) {
            if (num % 2 == 0) {
                result[evenIndex] = num;
                evenIndex += 2;
            } else {
                result[oddIndex] = num;
                oddIndex += 2;
            }
        }

        return result;
    }
};
