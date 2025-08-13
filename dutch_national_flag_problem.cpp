//
// Created by darion.yaphet on 2025/7/23.
//

/**
 * 给定一个由 红（Red）、白（White）、蓝（Blue） 三种颜色组成的数组（通常用整数 0、1、2 表示），请将数组 原地排序，使得：
 * 所有 0（红） 排在最前面
 * 所有 1（白） 排在中间
 * 所有 2（蓝） 排在最后
 * 最终数组应呈现为：[0, 0, ..., 1, 1, ..., 2, 2]
 *
 * 原地排序（不能使用额外数组）
 * 时间复杂度为 O(n)
 * 空间复杂度为 O(1)
 *
 * 三指针法（Three-way Partition）
 * 我们使用三个指针来维护数组中不同颜色的边界：
 * low（或 left）：指向 0 的右边界，所有在 low 左边的元素都是 0。
 * high（或 right）：指向 2 的左边界，所有在 high 右边的元素都是 2。
 * i：当前遍历指针，从左向右移动。
 */

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        int i = 0;

        while (i <= high) {
            if (nums[i] == 0) {
                swap(nums[i], nums[low]);
                low++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[high]);
                high--;
            } else {
                i++;
            }
        }
    }
};
