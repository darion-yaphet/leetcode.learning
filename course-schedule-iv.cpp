//
// Created by darion.yaphet on 2025/5/8.
//

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 可以将问题建模为一个图问题 ，其中课程是图中的节点，先修关系 [ai, bi] 表示从节点 ai 到节点 bi 的有向边。
     * 要判断课程 uj 是否是课程 vj 的先决条件，实际上是在图中检查是否存在一条从 uj 到 vj 的路径。
     *
     * Floyd-Warshall 算法是一种用于计算有向加权图中所有节点对之间的最短路径的动态规划算法。
     * 它也可以用来判断任意两点之间是否存在路径 （可达性问题），就像在课程先修关系问题中那样。
     *
     * 如果存在一个中间节点 k，使得从 i 到 k 有路径，并且从 k 到 j 也有路径，则从 i 到 j 存在路径。
     *
     * 转移方程为：
     * dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j])
     */
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int> > &prerequisites,
                                     vector<vector<int> > &queries) {
        // 初始化可达性矩阵
        vector<vector<bool> > reachable(numCourses, vector<bool>(numCourses, false));

        // 根据 prerequisites 构造直接可达性
        for (const auto &pre: prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            reachable[ai][bi] = true; // ai 是 bi 的直接先修课程
        }

        // 使用 Floyd-Warshall 算法计算所有节点对之间的可达性
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        // 处理每个查询
        vector<bool> answer;
        for (const auto &query: queries) {
            int uj = query[0], vj = query[1];
            answer.push_back(reachable[uj][vj]);
        }
        return answer;
    }
};
