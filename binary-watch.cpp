//
// Created by darion.yaphet on 2025/6/29.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/binary-watch/description
class Solution {
private:
    vector<string> result;

    // 小时和分钟对应的权重值
    vector<int> hourWeights = {1, 2, 4, 8};
    vector<int> minuteWeights = {1, 2, 4, 8, 16, 32};

public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> led(10, 0); // 10 个灯，默认都是灭的
        backtrack(led, 0, turnedOn);
        return result;
    }

    void backtrack(vector<int> &led, int start, int left) {
        if (left == 0) {
            // 所有灯都已选完，计算时间
            int hour = 0, minute = 0;
            for (int i = 0; i < 4; ++i) {
                if (led[i]) {
                    hour += hourWeights[i];
                }
            }

            for (int i = 4; i < 10; ++i) {
                if (led[i]) {
                    minute += minuteWeights[i - 4];
                }
            }

            if (hour <= 11 && minute <= 59) {
                string time = to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
                result.push_back(time);
            }

            return;
        }

        for (int i = start; i < 10; ++i) {
            led[i] = 1; // 选择这个位置点亮
            backtrack(led, i + 1, left - 1);
            led[i] = 0; // 撤销选择
        }
    }
};
