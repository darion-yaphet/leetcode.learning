//
// Created by darion.yaphet on 2024/10/23.
//

#include <iostream>
#include <vector>

// 合并两个有序子数组的函数
void merge(std::vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    std::vector<int> L(n1), R(n2);

    // 拷贝数据到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝L的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝R的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序函数
void mergeSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        // 找到中间点
        int mid = left + (right - left) / 2;

        // 分别对左右两半进行排序
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并两个有序子数组
        merge(arr, left, mid, right);
    }
}

// 主函数
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    std::cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Sorted array is \n";
    for (int i = 0; i < arr_size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
