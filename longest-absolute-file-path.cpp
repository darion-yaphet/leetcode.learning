//
// Created by darion.yaphet on 2025/5/18.
//

#include <string>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/longest-absolute-file-path/
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> pathLens; // 存储每层路径长度（不含'/'）
        int maxLen = 0;
        int currLen = 0; // 当前路径长度
        int level = 0; // 当前层级
        bool isFile = false;

        for (int i = 0; i < input.length(); ++i) {
            char c = input[i];

            if (c == '\n') {
                // 处理完一个完整路径段
                while (pathLens.size() > level) {
                    pathLens.pop_back();
                }

                if (isFile) {
                    // 如果是文件，更新最大长度
                    int totalLen = currLen;
                    totalLen += pathLens.size(); // 加上 '/' 的数量
                    maxLen = max(maxLen, totalLen);
                } else {
                    // 是目录，压入栈中
                    pathLens.push_back(currLen);
                }

                // 重置状态
                level = 0;
                currLen = 0;
                isFile = false;
            } else if (c == '\t') {
                level++;
                currLen = 0; // 重置当前长度，准备下一层
            } else {
                // 判断是否是文件
                if (c == '.') {
                    isFile = true;
                }
                currLen++;
            }
        }

        // 处理最后一个路径段
        while (pathLens.size() > level) {
            pathLens.pop_back();
        }

        if (isFile) {
            int totalLen = currLen;
            totalLen += pathLens.size(); // 加上 '/' 的数量
            maxLen = max(maxLen, totalLen);
        }

        return maxLen;
    }
};
