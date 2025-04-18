//
// Created by darion.yaphet on 2024/9/27.
//

// https://leetcode.cn/problems/open-the-lock

#include <queue>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string plusOne(string s, int j) {
        if (s[j] == '9') {
            s[j] = '0';
        } else {
            s[j] += 1;
        }
        return s;
    }

    string minusOne(string s, int j) {
        if (s[j] == '0') {
            s[j] = '9';
        } else {
            s[j] -= 1;
        }
        return s;
    }

    void BFS(string target) {
        queue<string> q;
        q.emplace("0000");

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    string up = plusOne(cur, j);
                    string down = minusOne(cur, j);
                    q.push(up);
                    q.push(down);
                }
            }
        }
    }

    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        int step = 0;
        queue<string> q;
        q.emplace("0000");
        visited.insert("0000");

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();

                if (deads.count(cur)) {
                    continue;
                }

                if (cur == target) {
                    return step;
                }

                for (int j = 0; j < 4; j++) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }

                    string down = minusOne(cur, j);
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};