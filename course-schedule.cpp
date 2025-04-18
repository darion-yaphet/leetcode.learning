//
// Created by Chenguang Wang on 2024/2/13.
//

#include <vector>

using namespace std;

class Solution {
private:
    vector<bool> visited;
    vector<bool> onPath;

    bool hasCycle = false;

    vector<int> *buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        auto *graph = new vector<int>[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = vector<int>();
        }

        for (auto &edge: prerequisites) {
            int from = edge[1];
            int to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }

    void traverse(vector<int> *graph, int s) {

        if (onPath[s]) {
            hasCycle = true;
        }

        if (visited[s] || hasCycle) {
            return;
        }

        visited[s] = true;
        onPath[s] = true;
        for (auto t: graph[s]) {
            traverse(graph, t);
        }

        onPath[s] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> *graph = buildGraph(numCourses, prerequisites);
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            traverse(graph, i);
        }

        return !hasCycle;
    }
};