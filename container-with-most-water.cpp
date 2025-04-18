//
// Created by Chenguang Wang on 2024/2/7.
//

// https://leetcode.cn/problems/container-with-most-water/description/

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
