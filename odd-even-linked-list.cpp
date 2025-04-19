//
// Created by darion.yaphet on 2025/4/19.
//

#include "ListNode.h"

// https://leetcode.cn/problems/odd-even-linked-list/description/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 空链表或只有一个节点直接返回
        if (!head || !head->next) {
            return head;
        }

        // 初始化指针
        ListNode* odd = head;       // 奇数索引节点的当前节点
        ListNode* even = head->next; // 偶数索引节点的当前节点
        ListNode* evenHead = even;   // 记录偶数链表的头节点

        // 遍历链表
        while (even && even->next) {
            odd->next = even->next;  // 奇数节点连接到下一个奇数节点
            odd = odd->next;         // 移动奇数指针
            even->next = odd->next;  // 偶数节点连接到下一个偶数节点
            even = even->next;       // 移动偶数指针
        }

        // 将奇数链表的尾部连接到偶数链表的头部
        odd->next = evenHead;

        return head; // 返回重新排序的链表头节点
    }
};