//
// Created by Chenguang Wang on 2024/2/14.
//

// https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
// 思路：
// 1. 快慢指针，快指针遍历整个链表，慢指针记录不重复的节点。
// 2. 快指针遍历到链表末尾时，慢指针指向的节点就是不重复的链表。
// 3. 删除重复节点，将慢指针的下一个节点指向重复节点的下一个节点。
// 4. 返回不重复的链表。

#include "ListNode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *slow = head, *fast = head;
        ListNode *dummy = slow;
        while (fast != nullptr) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            } else {
                fast = fast->next;
            }
        }
        return dummy;
    }
};