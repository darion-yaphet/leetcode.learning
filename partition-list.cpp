//
// Created by Chenguang Wang on 2024/1/26.
//

// https://leetcode.cn/problems/partition-list/description/

#include "ListNode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *lessDummy = new ListNode(-1);
        ListNode *less = lessDummy;

        ListNode *greaterDummy = new ListNode(-1);
        ListNode *greater = greaterDummy;

        ListNode *p = head;
        while (p != nullptr) {
            if (p->val >= x) {
                greater->next = p;
                greater = greater->next;
            } else {
                less->next = p;
                less = less->next;
            }

            ListNode *temp = p->next;
            p->next = nullptr;
            p = temp;
        }

        less->next = greaterDummy->next;
        return lessDummy->next;
    }
};