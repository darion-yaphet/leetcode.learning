//
// Created by Chenguang Wang on 2024/1/28.
//
#include <vector>
#include <unordered_map>

// https://leetcode.cn/problems/3sum/description/

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];

            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }

                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }

                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }

                if (nums[second] + nums[third] == target) {
                    result.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }

        return result;
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> result; // 存储所有满足条件的三元组
        int n = nums.size();

        // 对数组进行排序
        sort(nums.begin(), nums.end());

        // 遍历数组，固定第一个数
        for (int i = 0; i < n - 2; ++i) {
            // 跳过重复的固定数
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 双指针查找剩余两个数
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // 找到满足条件的三元组
                    result.push_back({nums[i], nums[left], nums[right]});

                    // 跳过重复的左指针和右指针
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }

                    // 移动指针继续查找
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left; // 和小于 0，移动左指针增大和
                } else {
                    --right; // 和大于 0，移动右指针减小和
                }
            }
        }

        return result;
    }
};