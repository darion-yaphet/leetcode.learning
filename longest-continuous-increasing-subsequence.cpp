//
// Created by Chenguang Wang on 2024/2/25.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();
        int dp[n];

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        int result = INT_MIN;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }

            result = max(result, dp[i]);
        }

        return result;
    }

    int findLengthOfLCIS2(vector<int> &nums) {
        int result = 0;
        int index = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) {
                index = i;
            }

            result = max(result, i - index + 1);
        }
        return result;
    }

};