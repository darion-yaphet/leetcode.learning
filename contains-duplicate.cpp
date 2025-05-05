//
// Created by darion.yaphet on 2025/5/5.
//

#include <vector>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> set;
        for (auto num: nums) {
            if (set.find(num) != set.end()) {
                return true;
            }
            set.insert(num);
        }

        return false;
    }
};
