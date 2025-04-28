//
// Created by Chenguang Wang on 2024/2/9.
//

// https://leetcode.cn/problems/gas-station/description/

#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int count = 0;
            while (count < n) {
                int j = (i + count) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                count++;
            }

            if (count == n) {
                return i;
            } else {
                i = i + count + 1;
            }
        }

        return -1;
    }

    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;    // 总油量
        int currentTank = 0;  // 当前油量
        int start = 0;        // 起点

        for (int i = 0; i < gas.size(); ++i) {
            totalTank += gas[i] - cost[i];    // 累积总油量
            currentTank += gas[i] - cost[i];  // 累积当前油量

            // 如果当前油量不足以到达下一站
            if (currentTank < 0) {
                start = i + 1;       // 更新起点为下一站
                currentTank = 0;     // 重置当前油量
            }
        }

        // 如果总油量不足，返回 -1；否则返回起点
        return totalTank >= 0 ? start : -1;
    }
};
