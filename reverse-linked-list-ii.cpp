//
// Created by Chenguang Wang on 2024/2/7.
//

// https://leetcode.cn/problems/reverse-linked-list-ii/description/

#include "ListNode.h"

class Solution {
private:
    ListNode *successor = nullptr;

    ListNode *reverseN(ListNode *head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }

        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

    ListNode *reverseBetween2(ListNode *head, int left, int right) {
        // 创建一个虚拟头节点，简化边界情况处理
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        // 移动prev指针到left-1的位置
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // start指向left位置的节点，end用于遍历并反转
        ListNode *start = prev->next;
        ListNode *end = start->next;

        // 反转从left到right之间的节点
        for (int i = 0; i < right - left; ++i) {
            start->next = end->next;
            end->next = prev->next;
            prev->next = end;
            end = start->next;
        }

        return dummy.next;
    }
};
