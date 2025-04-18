//
// Created by Chenguang Wang on 2024/1/31.
//

// https://leetcode.cn/problems/reverse-linked-list/description/

#include "ListNode.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    ListNode *reverseList2(ListNode *head) {
        ListNode *pre, *current, *next;
        pre = nullptr;
        current = head;
        next = head;

        while (current != nullptr) {
            next = current->next;
            // 逐个结点反转
            current->next = pre;
            // 更新指针位置
            pre = current;
            current = next;
        }
        return pre;
    }
};