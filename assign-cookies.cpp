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

    /**
     * 将孩子的胃口值数组 g 和饼干尺寸数组 s 都按升序排序。
     * 我们可以优先用最小的饼干满足最小胃口的孩子。
     *
     * 使用两个指针分别指向 g 和 s。
     * 如果当前饼干可以满足当前孩子（即 s[j]≥g[i]），则将该饼干分配给孩子，并移动两个指针。
     * 如果当前饼干无法满足当前孩子，则尝试用更大的饼干（即只移动饼干指针）。
     */
    int findContentChildren2(vector<int> &g, vector<int> &s) {
        // 对孩子的胃口值和饼干尺寸进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0; // 孩子指针
        int cookie = 0; // 饼干指针

        // 双指针遍历
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // 如果当前饼干可以满足当前孩子
                child++; // 移动孩子指针
            }
            cookie++; // 移动饼干指针
        }

        return child; // 返回满足的孩子数量
    }
};
