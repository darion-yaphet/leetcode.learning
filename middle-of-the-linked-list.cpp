//
// Created by Chenguang Wang on 2024/1/26.
//

// https://leetcode.cn/problems/middle-of-the-linked-list/description/

#include "ListNode.h"

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};