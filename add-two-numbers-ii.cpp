//
// Created by darion.yaphet on 2025/5/17.
//

#include <stack>
#include "ListNode.h"

using namespace std;

// https://leetcode.cn/problems/add-two-numbers-ii/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1, s2;

        // 把两个链表的值压入栈中
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = nullptr;
        int carry = 0;

        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
