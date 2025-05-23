//
// Created by Chenguang Wang on 2024/2/12.
//

// https://leetcode.cn/problems/intersection-of-two-arrays/description/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result;
        unordered_set<int> set(nums1.begin(), nums1.end());

        for (const auto num: nums2) {
            if (set.find(num) != set.end()) {
                result.emplace(num);
            }
        }
        return {result.begin(), result.end()};
    }
};