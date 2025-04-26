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

    /**
     * current_end：当前跳跃范围的边界。
     * farthest：在当前跳跃范围内能够到达的最远位置。
     *
     * 如果当前索引 i 达到了 current_end，说明需要进行一次新的跳跃：
     * 增加跳跃次数。
     * 更新 current_end 为 farthest，即新的跳跃范围。
     */
    int jump3(vector<int> &nums) {
        int jumps = 0;          // 记录跳跃次数
        int current_end = 0;    // 当前跳跃范围的边界
        int farthest = 0;       // 在当前跳跃范围内能够到达的最远位置

        for (int i = 0; i < nums.size() - 1; ++i) {
            // 更新当前跳跃范围内能够到达的最远位置
            farthest = max(farthest, i + nums[i]);

            // 如果到达了当前跳跃范围的边界，需要进行一次新的跳跃
            if (i == current_end) {
                jumps++;
                current_end = farthest;

                // 如果当前跳跃范围已经可以到达最后一个位置，提前返回
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};