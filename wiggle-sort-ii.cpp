//
// Created by darion.yaphet on 2025/4/20.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/wiggle-sort-ii/
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        // 1. 对数组进行排序
        sort(nums.begin(), nums.end());

        // 2. 分割数组为较小的一半和较大的一半
        int n = nums.size();
        vector<int> smallerHalf(nums.begin(), nums.begin() + (n + 1) / 2);
        vector<int> largerHalf(nums.begin() + (n + 1) / 2, nums.end());

        // 3. 交替插入
        int i = 0, j = 0, k = 0;
        while (k < n) {
            if (i < smallerHalf.size()) {
                nums[k++] = smallerHalf[i++];
            }
            if (j < largerHalf.size()) {
                nums[k++] = largerHalf[j++];
            }
        }

        // 4. 调整顺序以满足摆动条件
        for (int i = 1; i < n - 1; i += 2) {
            if (nums[i] < nums[i - 1]) {
                swap(nums[i], nums[i - 1]);
            }

            if (nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }

    void wiggleSort2(vector<int> &nums) {
        int n = nums.size();

        // 遍历数组并调整顺序
        for (int i = 0; i < n - 1; ++i) {
            if ((i % 2 == 0 && nums[i] > nums[i + 1]) ||
                (i % 2 == 1 && nums[i] < nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
};
