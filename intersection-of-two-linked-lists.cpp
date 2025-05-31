//
// Created by Chenguang Wang on 2024/1/26.
//

// https://leetcode.cn/problems/intersection-of-two-linked-lists

#include "ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            if (p1 == nullptr) {
                p1 = headB;
            } else {
                p1 = p1->next;
            }

            if (p2 == nullptr) {
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }
        return p1;
    }

    /**
     * 使用两个指针 pA 和 pB，分别从 headA 和 headB 开始遍历
     * 当 pA 到达末尾时，跳到 headB 继续走
     * 同理，pB 到达末尾后跳到 headA
     *
     * 如果两个链表相交，两个指针最终会相遇
     */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        return pA;
    }
};
