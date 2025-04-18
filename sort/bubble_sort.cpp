//
// Created by darion.yaphet on 2024/10/23.
//

#include <iostream>
#include <vector>

// 冒泡排序函数
void bubbleSort(std::vector<int> &arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // 如果当前元素比下一个元素大，则交换它们
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // 如果在这一轮排序中没有发生交换，说明数组已经有序，可以提前结束
        if (!swapped)
            break;
    }
}

// 主函数
int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    bubbleSort(arr);

    std::cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
