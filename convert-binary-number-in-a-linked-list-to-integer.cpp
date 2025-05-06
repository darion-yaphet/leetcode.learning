//
// Created by darion.yaphet on 2025/5/3.
//

#include "ListNode.h"

using namespace std;

// https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer
class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int result = 0;
        while (head != nullptr) {
            // 左移一位并加上当前节点的值
            result = (result << 1) + head->val;
            head = head->next;
        }
        return result;
    }
};
