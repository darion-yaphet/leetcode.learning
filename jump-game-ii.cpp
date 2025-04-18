//
// Created by Chenguang Wang on 2024/2/4.
//

// https://leetcode.cn/problems/jump-game-ii/description/

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int curDistance = 0;
        int result = 0;
        int nextDistance = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = max(nums[i] + i, nextDistance);
            if (i == curDistance) {
                result += 1;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1) {
                    break;
                }
            }
        }
        return result;
    }

    int jump2(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int curDistance = 0;
        int result = 0;
        int nextDistance = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            nextDistance = max(nums[i] + i, nextDistance);

            if (i == curDistance) {
                result += 1;
                curDistance = nextDistance;
            }
        }
        return result;
    }
};