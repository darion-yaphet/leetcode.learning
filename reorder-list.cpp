//
// Created by Chenguang Wang on 2024/2/21.
//

// https://leetcode.cn/problems/reorder-list/description/

#include "ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }

        ListNode *middle = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = middle->next;
        middle->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *current = head;
        ListNode *prev = nullptr;

        while (current != nullptr) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    void mergeList(ListNode *l1, ListNode *l2) {
        ListNode *l1_tmp;
        ListNode *l2_tmp;

        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};