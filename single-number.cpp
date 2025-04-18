//
// Created by Chenguang Wang on 2024/1/23.
//
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            num = num ^ nums[i];
        }
        return num;
    }
};