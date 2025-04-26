//
// Created by darion.yaphet on 2025/4/26.
//

#include <iostream>
#include <vector>

using namespace std;

// 调整以 index 为根的子树为最大堆
void heapify(vector<int> &nums, int n, int i) {
    int largest = i; // 初始化最大值为根节点
    int left = 2 * i + 1; // 左子节点索引
    int right = 2 * i + 2; // 右子节点索引

    // 如果左子节点存在且大于当前最大值
    if (left < n && nums[left] > nums[largest]) {
        largest = left;
    }

    // 如果右子节点存在且大于当前最大值
    if (right < n && nums[right] > nums[largest]) {
        largest = right;
    }

    // 如果最大值不是根节点，则交换并递归调整
    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest); // 递归调整受影响的子树
    }
}

// 堆排序主函数
void heapSort(vector<int> &nums) {
    int n = nums.size();

    // 构建初始最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(nums, n, i);
    }

    // 逐步将堆顶元素（最大值）移到数组末尾，并调整堆
    for (int i = n - 1; i > 0; --i) {
        swap(nums[0], nums[i]); // 将堆顶元素与末尾元素交换
        heapify(nums, i, 0); // 调整剩余部分为最大堆
    }
}

int main() {
    // 示例输入：一个未排序的数组
    vector<int> nums = {12, 11, 13, 5, 6, 7};

    cout << "排序前: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用堆排序函数
    heapSort(nums);

    cout << "排序后: ";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
