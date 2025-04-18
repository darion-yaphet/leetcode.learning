//
// Created by Chenguang Wang on 2024/2/13.
//

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (const auto &num: nums) {
            map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);

        for (const auto &[num, count]: map) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
};