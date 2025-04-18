//
// Created by darion.yaphet on 2024/10/27.
//

#include <vector>

using namespace std;

class Solution {
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[l];
        int i = l;
        for (int j = l + 1; j <= r; j++) {
            if (nums[j] < pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[l], nums[i]);
        return i;
    }

    int randomized_partition(vector<int> &nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        srand(time(nullptr));
        randomized_quicksort(nums, 0, (int) nums.size() - 1);
        return nums;
    }
};
