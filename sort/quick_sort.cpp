//
// Created by darion.yaphet on 2024/10/23.
//

#include <iostream>
#include <vector>

using namespace std;

// 分区函数：将数组分为两部分，并返回基准值的最终位置
// 用于将数组分为两部分，并返回基准值的最终位置。
// 遍历数组时，将小于基准值的元素交换到左侧部分。
// 最后将基准值放到正确的位置。
int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high]; // 选择最后一个元素作为基准值
    int i = low - 1; // i 是小于基准值部分的末尾索引

    for (int j = low; j < high; ++j) {
        if (nums[j] < pivot) {
            // 如果当前元素小于基准值
            ++i; // 扩展小于基准值的部分
            swap(nums[i], nums[j]); // 将当前元素交换到小于基准值的部分
        }
    }

    // 将基准值放到正确的位置
    swap(nums[i + 1], nums[high]);
    return i + 1; // 返回基准值的索引
}

// 快速排序主函数
// 通过选择一个“基准值”（pivot），将数组分为两部分：
// 一部分小于基准值，另一部分大于基准值，然后递归地对这两部分进行排序。
void quickSort(vector<int> &nums, int low, int high) {
    if (low < high) {
        // 终止条件：子数组长度为 0 或 1
        int pi = partition(nums, low, high); // 获取基准值的索引

        // 递归排序左侧部分和右侧部分
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

int main() {
    // 示例输入：一个未排序的数组
    vector<int> nums = {10, 7, 8, 9, 1, 5};

    cout << "排序前: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用快速排序函数
    quickSort(nums, 0, nums.size() - 1);

    cout << "排序后: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
