//
// Created by darion.yaphet on 2025/4/26.
//

#include <iostream>
#include <vector>
using namespace std;

// 插入排序函数
// 核心思想是将数组分为“已排序”和“未排序”两部分，逐步将未排序部分的元素插入到已排序部分的正确位置。
void insertionSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 1; i < n; ++i) {
        // 外层循环控制未排序部分的第一个元素
        int key = nums[i]; // 当前需要插入的元素
        int j = i - 1;

        // 内层循环：在已排序部分找到插入位置
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j]; // 将大于 key 的元素向后移动
            --j;
        }

        nums[j + 1] = key; // 将 key 插入到正确位置
    }
}

int main() {
    // 示例输入：一个未排序的数组
    vector<int> nums = {12, 11, 13, 5, 6};

    cout << "排序前: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用插入排序函数
    insertionSort(nums);

    cout << "排序后: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
