//
// Created by darion.yaphet on 2025/5/29.
//

#include <queue>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/jump-game-iii/
class Solution {
public:
    // 可以使用 BFS（广度优先搜索） 或 DFS（深度优先搜索） 来解决这个问题。
    // 为了避免重复访问和死循环，需要维护一个 visited 数组 来记录已经访问过的位置。
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (arr[curr] == 0) {
                return true;
            }

            // 向右跳
            int next1 = curr + arr[curr];
            if (next1 < n && !visited[next1]) {
                visited[next1] = true;
                q.push(next1);
            }

            // 向左跳
            int next2 = curr - arr[curr];
            if (next2 >= 0 && !visited[next2]) {
                visited[next2] = true;
                q.push(next2);
            }
        }
        return false;
    }
};
