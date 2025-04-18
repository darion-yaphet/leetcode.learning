//
// Created by Chenguang Wang on 2024/2/20.
//

// https://leetcode.cn/problems/next-greater-element-i

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<int> nextGreaterElement(vector<int> &nums) {
        int size = nums.size();
        stack<int> stack;
        vector<int> result;
        for (int i = size - 1; i >= 0; i--) {
            while (!stack.empty() && stack.top() <= nums[i]) {
                stack.pop();
            }

            result[i] = stack.empty() ? -1 : stack.top();
            stack.push(nums[i]);
        }
        return result;
    }

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> hashmap;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) {
                st.pop();
            }
            hashmap[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = hashmap[nums1[i]];
        }
        return res;
    }
};