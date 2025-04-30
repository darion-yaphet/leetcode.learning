//
// Created by darion.yaphet on 2025/4/30.
//

#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/the-number-of-beautiful-subsets/
class Solution {
public:
    // 使用回溯算法（Backtracking）枚举所有可能的子集，并检查是否满足美丽子集的条件。
    // 对数组进行排序，减少不必要的递归分支。
    // 使用一个计数器记录每个数字出现的次数，避免重复计算相同数字的情况。
    int beautifulSubsets(vector<int> &nums, int k) {
        // 统计每个数字的频率
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }

        // 将数字按升序排序
        vector<int> uniqueNums;
        for (auto &[num, _]: freq) {
            uniqueNums.push_back(num);
        }
        sort(uniqueNums.begin(), uniqueNums.end());

        // 回溯函数
        function<int(int)> backtrack = [&](int index) -> int {
            // 只有空集
            if (index == uniqueNums.size()) {
                return 1;
            }

            // 当前数字
            int current = uniqueNums[index];
            int count = freq[current];

            // 不选择当前数字
            int result = backtrack(index + 1);

            // 检查是否可以选择当前数字
            bool canChoose = true;
            if (freq.find(current - k) != freq.end() && freq[current - k] > 0) {
                canChoose = false; // 如果存在 current - k，则不能选择 current
            }

            if (canChoose) {
                // 选择当前数字（可以选择 1 到 count 次）
                freq[current]--;
                result += count * backtrack(index + 1);
                freq[current]++; // 回溯：恢复状态
            }

            return result;
        };

        // 调用回溯函数并减去空集
        return backtrack(0) - 1;
    }
};
