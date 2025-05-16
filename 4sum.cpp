//
// Created by darion.yaphet on 2025/5/16.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/4sum/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) {
                            left += 1;
                        }

                        while (right > left && nums[right] == nums[right - 1]) {
                            right -= 1;
                        }

                        left += 1;
                        right -= 1;
                    } else if (sum < target) {
                        left += 1;
                    } else {
                        right -= 1;
                    }
                }
            }
        }
        return result;
    }
};
