//
// Created by darion.yaphet on 2025/4/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 桶排序函数
// 桶排序（Bucket Sort）是一种分布式排序算法，特别适合处理数据分布均匀 的场景。
// 它的核心思想是将数据分配到多个“桶”中，每个桶单独排序，最后将所有桶中的数据合并成最终结果。
void bucketSort(vector<float>& nums) {
    int n = nums.size();

    // 创建 n 个空桶
    vector<vector<float>> buckets(n);

    // 将数据分配到桶中
    for (int i = 0; i < n; ++i) {
        int bucketIndex = n * nums[i]; // 根据数值范围确定桶的索引
        buckets[bucketIndex].push_back(nums[i]);
    }

    // 对每个桶中的数据进行排序
    for (int i = 0; i < n; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 合并桶中的数据
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (float value : buckets[i]) {
            nums[index++] = value;
        }
    }
}

int main() {
    // 示例输入：一个未排序的浮点数组
    vector<float> nums = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.50};

    cout << "排序前: ";
    for (float num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用桶排序函数
    bucketSort(nums);

    cout << "排序后: ";
    for (float num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}