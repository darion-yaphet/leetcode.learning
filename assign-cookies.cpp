//
// Created by Chenguang Wang on 2024/2/4.
//

// https://leetcode.cn/problems/assign-cookies/description/

#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && g[i] <= s[index]) {
                index -= 1;
                result += 1;
            }
        }
        return result;
    }
};