//
// Created by Chenguang Wang on 2024/1/28.
//

// https://leetcode.cn/problems/swap-nodes-in-pairs/description/

#include "ListNode.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }

    // 两两交换链表中的相邻节点
    ListNode* swapPairs2(ListNode* head) {
        // 创建虚拟头节点
        ListNode dummy(0);
        dummy.next = head;

        // 定义指针 prev，指向当前组的前一个节点
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            // 获取当前组的两个节点
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // 调整指针顺序
            prev->next = second;       // prev 指向 second
            first->next = second->next; // first 指向 second 的下一个节点
            second->next = first;      // second 指向 first

            // 更新 prev 指针到下一组的前一个节点
            prev = first;
        }

        // 返回新的链表头节点
        return dummy.next;
    }
};