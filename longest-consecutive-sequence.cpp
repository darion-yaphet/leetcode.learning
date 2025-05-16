//
// Created by Chenguang Wang on 2024/2/22.
//

// https://leetcode.cn/problems/longest-consecutive-sequence/description/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int result = 1;
        int counter = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 1) {
                counter += 1;
                result = max(result, counter);
            } else if (nums[i] - nums[i - 1] == 0) {
                // skip
            } else {
                counter = 1;
            }
        }
        return result;
    }

    int longestConsecutive2(vector<int> &nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longest = 0;
        for (int num: numSet) {

            // 判断当前数字是否是某个连续序列的第一个数字。
            // 也就是说，如果 num - 1 不在集合中，说明 num 是起始点。

            // 只处理连续序列的起始点
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;

                // 向上查找连续序列
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};
