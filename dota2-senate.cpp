//
// Created by darion.yaphet on 2025/4/26.
//

#include <iostream>
#include <string>

using namespace std;

// https://leetcode.cn/problems/dota2-senate/description/
class Solution {
public:
    string predictPartyVictory(string senate) {
        // 使用两个队列分别存储天辉和夜魇参议员的索引位置
        queue<int> radiant, dire;
        int n = senate.size();

        // 初始化队列：将每个参议员的索引存入对应的队列
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            // 取出当前轮次的两个参议员
            int rIndex = radiant.front();
            radiant.pop();
            int dIndex = dire.front();
            dire.pop();

            // 比较索引位置，决定谁可以继续留在游戏中
            if (rIndex < dIndex) {
                // 如果天辉参议员先投票，则夜魇参议员被禁止权利
                // 天辉参议员重新加入队列，位置为当前索引 + n（表示下一轮）
                radiant.push(rIndex + n);
            } else {
                // 如果夜魇参议员先投票，则天辉参议员被禁止权利
                // 夜魇参议员重新加入队列，位置为当前索引 + n
                dire.push(dIndex + n);
            }
        }

        // 最后剩下的非空队列代表胜利的一方
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
