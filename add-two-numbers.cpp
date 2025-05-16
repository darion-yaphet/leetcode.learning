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

    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
        ListNode dummy(0); // 虚拟头节点
        ListNode *curr = &dummy; // 当前节点指针
        int carry = 0; // 进位值

        while (l1 || l2 || carry > 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int sum = x + y + carry;
            int digit = sum % 10;
            carry = sum / 10;

            curr->next = new ListNode(digit);
            curr = curr->next;

            if (l1 != nullptr) {
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return dummy.next;
    }
};
