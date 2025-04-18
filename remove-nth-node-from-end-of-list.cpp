//
// Created by Chenguang Wang on 2024/1/26.
//

// https://leetcode.cn/problems/remove-nth-node-from-end-of-list

#include "ListNode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < n && fast != nullptr; i++) {
            fast = fast->next;
        }

        fast = fast->next;

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};