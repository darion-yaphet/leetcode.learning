//
// Created by Chenguang Wang on 2024/2/15.
//

// https://leetcode.cn/problems/sort-list/description/

#include "ListNode.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (head == nullptr) {
            return head;
        }

        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }

        ListNode *middle = slow;
        return merge(sortList(head, middle), sortList(middle, tail));
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }

        return dummyHead->next;
    }

    ListNode* sortList2(ListNode* head) {
        if (!head || !head->next) return head; // 空链表或单节点链表直接返回

        // 第一步：找到链表的中点
        ListNode* mid = findMiddle2(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr; // 断开链表

        // 第二步：递归排序左右两部分
        ListNode* left = sortList2(head);      // 排序左半部分
        ListNode* right = sortList2(rightHead); // 排序右半部分

        // 第三步：合并两个已排序的链表
        return merge2(left, right);
    }

    ListNode* findMiddle2(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge2(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // 创建虚拟头节点
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2; // 连接剩余部分
        return dummy.next;
    }
};