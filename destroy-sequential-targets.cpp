//
// Created by darion.yaphet on 2025/4/21.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/destroy-sequential-targets/

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        // 哈希表 count[remainder] 表示模 space 的余数 remainder 出现的次数
        unordered_map<int, int> count;
        // 哈希表 first[remainder] 表示模 space 的余数 remainder 对应的最小 nums[i]
        unordered_map<int, int> first;

        for (int num : nums) {
            int remainder = num % space;

            // 更新 count 和 first
            count[remainder]++;
            if (first.find(remainder) == first.end() || num < first[remainder]) {
                first[remainder] = num;
            }
        }

        // 找到出现次数最多的余数，并记录对应的最小 nums[i]
        int maxCount = 0, result = INT32_MAX;
        for (const auto& [remainder, cnt] : count) {
            if (cnt > maxCount) {
                maxCount = cnt;
                result = first[remainder];
            } else if (cnt == maxCount) {
                result = min(result, first[remainder]);
            }
        }

        return result;
    }
};

// 测试代码
int main() {
    Solution solution;

    vector<int> nums = {6, 2, 5};
    int space = 10;

    cout << "Optimal nums[i]: " << solution.destroyTargets(nums, space) << endl;
    return 0;
}