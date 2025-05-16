//
// Created by darion.yaphet on 2025/5/14.
//

#include <string>
#include <sstream>

using namespace std;

// https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/
class Solution {
public:
    /**
     * 利用栈来模拟节点的消耗过程
     *
     * 前序遍历的顺序是：根节点 -> 左子树 -> 右子树
     * 每个非空节点需要有两个子节点（左子节点和右子节点），而空节点（用 # 表示）没有子节点。
     */
    bool isValidSerialization(string preorder) {
        // 初始化槽位计数器
        int slots = 1;

        // 使用 stringstream 分割字符串
        stringstream ss(preorder);
        string token;

        while (getline(ss, token, ',')) {
            // 每处理一个节点，减少一个槽位
            --slots;

            // 如果槽位不足，直接返回 false
            if (slots < 0) {
                return false;
            }

            // 如果当前节点不是空节点，则增加两个槽位
            if (token != "#") {
                slots += 2;
            }
        }

        // 最终槽位必须为 0
        return slots == 0;
    }
};
