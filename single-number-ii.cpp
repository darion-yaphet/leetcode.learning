//
// Created by Chenguang Wang on 2024/1/23.
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }

        for (auto iter = map.begin(); iter != map.end(); iter++) {
            if (iter->second == 1) {
                return iter->first;
            }
        }
        return 0;
    }
};