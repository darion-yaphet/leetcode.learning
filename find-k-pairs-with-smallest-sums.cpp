//
// Created by Chenguang Wang on 2024/1/28.
//

// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            result.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return result;
    }

    vector<vector<int>> kSmallestPairs2(vector<int>& nums1, vector<int>& nums2, int k) {
        // 定义结果集
        vector<vector<int>> result;

        // 如果任意一个数组为空，直接返回空结果
        if (nums1.empty() || nums2.empty()) {
            return result;
        }

        // 定义最小堆，存储 (和, nums1 的索引, nums2 的索引)
        auto cmp = [&](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first; // 按照和从小到大排序
        };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> minHeap(cmp);

        // 初始化堆，将 nums1 的前 min(k, len(nums1)) 个元素与 nums2[0] 组合
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            minHeap.push({nums1[i] + nums2[0], {i, 0}});
        }

        // 找到前 k 个最小的数对
        while (k-- > 0 && !minHeap.empty()) {
            // 取出当前和最小的数对
            auto [sum, indices] = minHeap.top();
            minHeap.pop();

            int i = indices.first, j = indices.second;
            result.push_back({nums1[i], nums2[j]});

            // 如果 nums2 中还有下一个元素，将其加入堆中
            if (j + 1 < n) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return result;
    }
};