//
// Created by darion.yaphet on 2025/5/3.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/minimum-domino-rotations-for-equal-row
class Solution {
public:
    // 遍历每个目标值 x，分别尝试将 tops 和 bottoms 转换为 x。
    // 计算旋转次数时，统计需要旋转的多米诺骨牌数量。
    // 如果某个位置既不能使 tops[i] == x，也不能使 bottoms[i] == x，则当前 x 不可行。
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        int n = tops.size();

        // 尝试将 tops 或 bottoms 全部变为 tops[0]
        int result = check(tops[0], tops, bottoms);
        if (result != -1 || tops[0] == bottoms[0]) {
            return result;
        }

        // 否则尝试将 tops 或 bottoms 全部变为 bottoms[0]
        return check(bottoms[0], tops, bottoms);
    }

    int check(int x, const vector<int> &tops, const vector<int> &bottoms) {
        int n = tops.size();
        int rotationsA = 0, rotationsB = 0;

        for (int i = 0; i < n; ++i) {
            // 如果 tops[i] 和 bottoms[i] 都不等于 x，则无法完成
            if (tops[i] != x && bottoms[i] != x) {
                return -1;
            }

            // 如果 tops[i] 不等于 x，则需要旋转到 tops
            if (tops[i] != x) {
                rotationsA++;
            }

            // 如果 bottoms[i] 不等于 x，则需要旋转到 bottoms
            if (bottoms[i] != x) {
                rotationsB++;
            }
        }

        // 返回将 tops 或 bottoms 转换为 x 所需的最小旋转次数
        return min(rotationsA, rotationsB);
    }
};
