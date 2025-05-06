//
// Created by darion.yaphet on 2025/5/6.
//

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 1; i < k; i++) {
            fast = fast->next;
        }

        ListNode *firstK = fast;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        std::swap(firstK->val, slow->val);
        return head;
    }
};
