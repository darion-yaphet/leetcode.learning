//
// Created by Chenguang Wang on 2024/2/14.
//

// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
// 删除排序链表中的重复元素 II
// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回已排序的链表 。
// 思路：
// 1. 创建一个虚拟节点 dummy，指向头结点 head。
// 2. 创建一个指针 slow，初始化为 dummy。
// 3. 创建一个指针 fast，初始化为 head。
// 4. 在循环中，如果 slow->val 和 fast->val 相等，则将 fast 向后移动一位。
// 5. 如果 slow->val 和 fast->val 不相等，则将 slow 向后移动一位，并将 fast 向后移动一位。
// 6. 循环结束后，返回 dummy->next，即删除重复节点后的链表的头结点。

#include "ListNode.h"

class Solution {
public:
//    ListNode *deleteDuplicates(ListNode *head) {
//        ListNode *slow = head, *fast = head;
//        ListNode *dummy = slow;
//        while (fast != nullptr) {
//            if (slow->val != fast->val) {
//                slow->next = fast;
//                slow = slow->next;
//                fast = fast->next;
//            } else {
//                fast = fast->next;
//            }
//        }
//        return dummy;
//    }

    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *current = dummy;
        while (current->next != nullptr && current->next->next != nullptr) {
            if (current->next->val != current->next->next->val) {
                current = current->next;
            } else {
                int value = current->next->val;
                while (current->next && current->next->val == value) {
                    current->next = current->next->next;
                }
            }
        }
        return dummy->next;
    }
};
