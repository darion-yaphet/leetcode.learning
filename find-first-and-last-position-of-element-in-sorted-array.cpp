//
// Created by Chenguang Wang on 2024/1/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                int l = mid, r = mid;
                while (l >= 0 && nums[l] == target) {
                    l -= 1;
                }

                while (r <= nums.size() - 1 && nums[r] == target) {
                    r += 1;
                }
                return {l + 1, r - 1};
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {-1, -1};
    }
};