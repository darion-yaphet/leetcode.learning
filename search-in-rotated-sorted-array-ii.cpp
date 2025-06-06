//
// Created by darion.yaphet on 2024/10/21.
//

// https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/description/
// https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/solutions/704686/sou-suo-xuan-zhuan-pai-xu-shu-zu-ii-by-l-0nmp/

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 当 nums[left] == nums[mid] && nums[mid] == nums[right] 时，
     * 无法判断哪一部分是有序的，这时需要通过 收缩边界 来跳过这些不确定的重复值。
     */
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }

        if (n == 1) {
            return nums[0] == target;
        }

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }

            // 特殊情况处理：无法判断哪边有序
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                ++l;
                --r;
            } else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
