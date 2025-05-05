//
// Created by darion.yaphet on 2025/5/5.
//

#include "ListNode.h"

class Solution {
public:
    /**
     * 遍历链表 list1，找到下标为 a-1 和 b+1 的节点（分别称为 prevA 和 nextB）。
     * 将 prevA 的 next 指向 list2 的头节点。
     * 遍历 list2 找到其尾节点，并将其 next 指向 nextB。
     */
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *prevA = nullptr;
        ListNode *nextB = nullptr;
        ListNode *current = list1;

        for (int i = 0; current != nullptr; i++) {
            if (i == a - 1) {
                prevA = current;
            }

            if (i == b + 1) {
                nextB = current;
                break;
            }

            current = current->next;
        }

        if (prevA) {
            prevA->next = list2;
        } else {
            list1 = list2;
        }

        current = list2;
        while (current && current->next) {
            current = current->next;
        }
        // 将 list2 的尾节点指向 nextB
        current->next = nextB;
        return list1;
    }
};
