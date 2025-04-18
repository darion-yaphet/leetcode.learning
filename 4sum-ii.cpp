//
// Created by Chenguang Wang on 2024/2/12.
//

// https://leetcode.cn/problems/4sum-ii

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int s1 = nums1.size(), s2 = nums2.size(), s3 = nums3.size(), s4 = nums4.size();
        unordered_map<int, int> map;
        int result = 0;
        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                int key = nums1[i] + nums2[j];
                map[key] += 1;
            }
        }

        for (int i = 0; i < s3; i++) {
            for (int j = 0; j < s4; j++) {
                int key = (nums3[i] + nums4[j]) * -1;
                if (map.find(key) != map.end()) {
                    result += 1;
                }
            }
        }

        return result;
    }
};