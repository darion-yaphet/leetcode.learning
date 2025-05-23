//
// Created by darion.yaphet on 2024/11/5.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int> &nums, int k) {
        int n = nums.size();
        int cnt = 0;
        vector ans(n - k + 1, -1);
        for (int i = 0; i < n; i++) {
            cnt = i == 0 || nums[i] - nums[i - 1] != 1 ? 1 : cnt + 1;
            if (cnt >= k) {
                ans[i - k + 1] = nums[i];
            }
        }
        return ans;
    }
};
