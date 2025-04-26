//
// Created by Chenguang Wang on 2024/1/20.
//

// https://leetcode.cn/problems/jump-game/description/

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() <= 1) {
            return true;
        }

        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }

    bool canJump2(vector<int> &nums) {
        int max_reachable = 0; // 当前能够到达的最远距离
        for (int i = 0; i < nums.size(); ++i) {
            if (i > max_reachable) {
                // 如果当前位置不可达
                return false;
            }
            // 更新最远可达位置
            max_reachable = max(max_reachable, i + nums[i]);
            // 如果已经可以到达最后一个位置，提前返回 true
            if (max_reachable >= nums.size() - 1) {
                return true;
            }
        }
        return max_reachable >= nums.size() - 1;
    }
};
