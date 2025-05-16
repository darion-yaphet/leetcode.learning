//
// Created by darion.yaphet on 2025/5/16.
//

#include <vector>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/number-of-arithmetic-triplets/
class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int result = 0;
        unordered_set<int> set(nums.begin(), nums.end());

        for (auto num: nums) {
            if (set.count(num + diff) && set.count(num + 2 * diff)) {
                result += 1;
            }
        }

        return result;
    }
};
