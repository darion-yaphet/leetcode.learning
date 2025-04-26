//
// Created by darion.yaphet on 2024/10/23.
//

#include <iostream>
#include <vector>
using namespace std;

// 希尔排序函数
// 希尔排序（Shell Sort）是一种基于插入排序的改进算法，也被称为缩小增量排序 。
// 它的核心思想是通过分组的方式逐步减少数据之间的距离，使得数组逐渐趋于有序，从而提高插入排序的效率。
void shellSort(vector<int> &nums) {
    int n = nums.size();

    // 初始增量为数组长度的一半，逐步减半
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个子数组进行插入排序
        for (int i = gap; i < n; ++i) {
            int temp = nums[i]; // 当前需要插入的元素
            int j;

            // 插入排序的核心逻辑
            for (j = i; j >= gap && nums[j - gap] > temp; j -= gap) {
                nums[j] = nums[j - gap];
            }

            nums[j] = temp; // 插入到正确位置
        }
    }
}

int main() {
    // 示例输入：一个未排序的数组
    vector<int> nums = {12, 34, 54, 2, 3};

    cout << "排序前: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用希尔排序函数
    shellSort(nums);

    cout << "排序后: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
