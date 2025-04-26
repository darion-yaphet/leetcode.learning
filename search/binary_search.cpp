//
// Created by darion.yaphet on 2025/4/26.
//

#include <iostream>
#include <vector>
using namespace std;

// 二分查找函数
int binarySearch(const vector<int> &nums, int target) {
    int left = 0; // 左边界
    int right = nums.size() - 1; // 右边界

    while (left <= right) {
        // 当左边界小于等于右边界时继续搜索
        int mid = left + (right - left) / 2; // 计算中间位置，避免溢出

        if (nums[mid] == target) {
            // 找到目标值
            return mid;
        } else if (nums[mid] < target) {
            // 目标值在右半部分
            left = mid + 1;
        } else {
            // 目标值在左半部分
            right = mid - 1;
        }
    }

    return -1; // 如果未找到目标值，返回 -1
}

int main() {
    // 示例输入：一个升序数组和目标值
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(9);
    int target;

    cout << "请输入要查找的目标值: ";
    cin >> target;

    // 调用二分查找函数
    int result = binarySearch(nums, target);

    if (result != -1) {
        cout << "目标值 " << target << " 在数组中的索引为: " << result << endl;
    } else {
        cout << "目标值 " << target << " 不在数组中。" << endl;
    }

    return 0;
}
