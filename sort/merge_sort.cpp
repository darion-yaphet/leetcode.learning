//
// Created by darion.yaphet on 2024/10/23.
//

#include <iostream>
#include <vector>

using namespace std;

// 合并两个有序子数组
// 将数组分成两半，分别对两半进行排序，然后将两个有序的子数组合并成一个有序数组。
void merge(vector<int>& nums, int left, int mid, int right) {
    // 创建临时数组存储合并结果
    vector<int> temp(right - left + 1);

    int i = left;     // 左子数组的起始索引
    int j = mid + 1;  // 右子数组的起始索引
    int k = 0;        // 临时数组的索引

    // 比较左右子数组的元素，按顺序放入临时数组
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // 将剩余的左子数组元素放入临时数组
    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    // 将剩余的右子数组元素放入临时数组
    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // 将临时数组的内容复制回原数组
    for (int idx = 0; idx < temp.size(); ++idx) {
        nums[left + idx] = temp[idx];
    }
}

// 归并排序主函数
void mergeSort(vector<int>& nums, int left, int right) {
    // 终止条件：子数组长度为 0 或 1
    if (left >= right) {
        return;
    }

    // 计算中间位置
    int mid = left + (right - left) / 2;

    // 递归排序左右两部分
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    // 合并两个有序子数组
    merge(nums, left, mid, right);
}

int main() {
    // 示例输入：一个未排序的数组
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};

    cout << "排序前: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用归并排序函数
    mergeSort(nums, 0, nums.size() - 1);

    cout << "排序后: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}