//
// Created by darion.yaphet on 2024/10/23.
//

#include <iostream>
#include <vector>

// 函数用于交换两个元素的值
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 划分函数，返回基准元素的最终位置
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = (low - 1); // 小于基准的元素的索引

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            i++; // 小于基准的元素索引加1
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 快速排序函数
void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        // pi是基准的索引
        int pi = partition(arr, low, high);

        // 分别对划分后左右两部分递归排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 主函数
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
