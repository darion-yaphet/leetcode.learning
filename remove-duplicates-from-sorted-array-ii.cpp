//
// Created by Chenguang Wang on 2024/1/18.
//

// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int slow = 2, fast = 2;
        for (; fast < n; fast++) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }

    int removeDuplicates2(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 0; // 指向插入位置
        int count = 1; // 记录重复次数
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] == nums[j - 1]) {
                count++;
            } else {
                count = 1;
            }

            // 只保留最多两次重复
            if (count <= 2) {
                ++i;
                nums[i] = nums[j];
            }
        }

        return i + 1; // 新长度是 i + 1
    }

    int removeDuplicates3(vector<int> &nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int index = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }
};
