//
// Created by darion.yaphet on 2024/10/27.
//

#include <vector>

using namespace std;

class Solution {
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[l];
        int i = l;
        for (int j = l + 1; j <= r; j++) {
            if (nums[j] < pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[l], nums[i]);
        return i;
    }

    int randomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        srand(time(nullptr));
        randomized_quicksort(nums, 0, (int) nums.size() - 1);
        return nums;
    }

    // 合并两个有序子数组
    void merge(vector<int> &nums, int left, int mid, int right, vector<int> &temp) {
        // 将 nums[left..mid] 和 nums[mid+1..right] 合并到 temp 中
        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // 处理剩余元素
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // 将 temp 中的结果复制回 nums
        for (int idx = left; idx <= right; ++idx) {
            nums[idx] = temp[idx];
        }
    }

    // 归并排序的递归实现
    void mergeSort(vector<int> &nums, int left, int right, vector<int> &temp) {
        if (left >= right) return; // 基本情况：子数组长度为 1

        int mid = left + (right - left) / 2;

        // 分解：递归排序左右两部分
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid + 1, right, temp);

        // 合并：将两个有序子数组合并
        merge(nums, left, mid, right, temp);
    }

    void sortArray2(vector<int> &nums) {
        int n = nums.size();
        // 如果数组为空或只有一个元素，直接返回
        if (n <= 1) {
            return;
        }

        // 创建一个临时数组用于合并操作
        vector<int> temp(n);

        // 调用归并排序
        mergeSort(nums, 0, n - 1, temp);
    }
};
