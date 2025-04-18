//
// Created by Chenguang Wang on 2024/2/14.
//
#include "ListNode.h"

class Solution {
public:
//    ListNode *rotateRight(ListNode *head, int k) {
//        if (k == 0 || head == nullptr || head->next == nullptr) {
//            return head;
//        }
//
//        ListNode *count = head;
//        int size = 0;
//        while (count->next != nullptr) {
//            count = count->next;
//            size += 1;
//        }
//
//        if (size % k == 0) {
//            return head;
//        }
//        ListNode *fast = head;
//        ListNode *slow = head;
//
//        for (int i = 0; i < k % size; i++) {
//            fast = fast->next;
//        }
//
//        while (fast->next != nullptr) {
//            fast = fast->next;
//            slow = slow->next;
//        }
//
//        ListNode *newHead = slow->next;
//        slow->next = nullptr;
//        fast->next = head;
//        return newHead;
//    }

    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }

        int n = 1;
        ListNode *iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
            n++;
        }

        int add = n - k % n;
        if (add == n) {
            return head;
        }

        iter->next = head;
        while (add--) {
            iter = iter->next;
        }

        ListNode *ret = iter->next;
        iter->next = nullptr;
        return ret;
    }

};