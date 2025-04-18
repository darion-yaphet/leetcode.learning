//
// Created by darion.yaphet on 2024/10/23.
//

#include <iostream>
#include <vector>

// 希尔排序函数
void shellSort(std::vector<int> &arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 主函数
int main() {
    std::vector<int> arr = {9, 8, 3, 7, 5, 6, 4, 1};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    shellSort(arr);

    std::cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
