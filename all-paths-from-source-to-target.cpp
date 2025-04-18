//
// Created by Chenguang Wang on 2024/1/31.
//

// https://leetcode.cn/problems/all-paths-from-source-to-target/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return result;
    }

    void traverse(vector<vector<int>> &graph, int s, vector<int> path) {
        path.push_back(s);

        int n = graph.size();
        if (s == n - 1) {
            result.push_back(path);
            path.pop_back();
            return;
        }

        for (int v: graph[s]) {
            traverse(graph, v, path);
        }

        path.pop_back();
    }
};