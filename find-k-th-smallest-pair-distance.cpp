//
// Created by Chenguang Wang on 2024/1/28.
//

// https://leetcode.cn/problems/find-k-th-smallest-pair-distance

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; ++i) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            while (curr < n && arr[curr].first <= w) {
                pq.push(arr[curr].second);
                curr++;
            }

            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};