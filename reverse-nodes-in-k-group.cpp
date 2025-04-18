//
// Created by Chenguang Wang on 2024/2/14.
//

// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/

#include "ListNode.h"

class Solution {
public:
    ListNode *reverse(ListNode *a, ListNode *b) {
        ListNode *pre, *current, *next;
        pre = nullptr;
        current = a;
        next = a;

        while (current != b) {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *a, *b;
        a = b = head;

        for (int i = 0; i < k; i++) {
            // 不足 k 个，不需要反转，base case
            if (b == nullptr) {
                return head;
            }
            b = b->next;
        }

        // 反转前 k 个元素
        ListNode *newHead = reverse(a, b);
        // 递归反转后续链表并连接起来
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};