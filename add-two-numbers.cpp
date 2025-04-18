//
// Created by Chenguang Wang on 2024/1/26.
//

// https://leetcode.cn/problems/add-two-numbers/description/

#include "ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
            }

            if (l2 != nullptr) {
                sum += l2->val;
            }

            if (carry != 0) {
                sum += 1;
            }

            if (sum > 9) {
                sum %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            head->next = new ListNode(sum);
            head = head->next;

            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        if (carry != 0) {
            head->next = new ListNode(1);
        }

        return dummy->next;
    }
};