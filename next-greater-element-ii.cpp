//
// Created by Chenguang Wang on 2024/2/20.
//

// https://leetcode.cn/problems/next-greater-element-ii

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> stack;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stack.empty() && nums[stack.top()] < nums[i % n]) {
                result[stack.top()] = nums[i % n];
                stack.pop();
            }
            stack.push(i % n);
        }
        return result;
    }
};