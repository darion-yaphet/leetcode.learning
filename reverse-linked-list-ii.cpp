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
};