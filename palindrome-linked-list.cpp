//
// Created by Chenguang Wang on 2024/1/28.
//

// https://leetcode.cn/problems/palindrome-linked-list/description/

#include "ListNode.h"
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        stack<int> stack;
        ListNode *h = head;
        while (h != nullptr) {
            stack.push(h->val);
            h = h->next;
        }

        while (head != nullptr) {
            if (head->val != stack.top()) {
                return false;
            }

            stack.pop();
            head = head->next;
        }
        return true;
    }
};