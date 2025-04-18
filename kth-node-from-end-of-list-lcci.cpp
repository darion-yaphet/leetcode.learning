//
// Created by Chenguang Wang on 2024/1/26.
//

// https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/description/

#include "ListNode.h"

class Solution {
public:
    int kthToLast(ListNode *head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};