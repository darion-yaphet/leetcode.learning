//
// Created by Chenguang Wang on 2024/1/24.
//

// https://leetcode.cn/problems/linked-list-cycle/description/

#include "ListNode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 空链表或只有一个节点的情况
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *fast = head->next, *slow = head;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }

            slow = slow->next;          // 慢指针每次移动一步
            fast = fast->next->next;    // 快指针每次移动两步
        }

        return true;
    }

    bool hasCycle2(ListNode* head) {
        if (!head || !head->next) return false; // 空链表或只有一个节点的情况

        ListNode* slow = head; // 慢指针
        ListNode* fast = head; // 快指针

        while (fast && fast->next) {
            slow = slow->next;           // 慢指针每次移动一步
            fast = fast->next->next;     // 快指针每次移动两步

            if (slow == fast) {          // 如果快慢指针相遇，说明有环
                return true;
            }
        }

        return false; // 遍历结束，没有环
    }
};