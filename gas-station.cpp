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
};
