//
// Created by darion.yaphet on 2025/4/26.
//

#include <iostream>
#include <vector>
using namespace std;

// 选择排序函数
void selectionSort(vector<int> &nums) {
    int n = nums.size();

    // 外层循环：遍历数组，确定当前最小值的位置
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // 假设当前索引为最小值的索引

        // 内层循环：在未排序部分找到最小值的索引
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j; // 更新最小值的索引
            }
        }

        // 如果找到更小的值，则交换
        if (minIndex != i) {
            swap(nums[i], nums[minIndex]);
        }
    }
}

int main() {
    // 示例输入：一个未排序的数组
    vector<int> nums = {64, 25, 12, 22, 11};

    cout << "排序前: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用选择排序函数
    selectionSort(nums);

    cout << "排序后: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
