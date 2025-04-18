//
// Created by Chenguang Wang on 2024/1/26.
//

// https://leetcode.cn/problems/merge-k-sorted-lists

#include "ListNode.h"

#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        // 创建虚拟头节点
        ListNode dummy(0);
        ListNode *p = &dummy;

        // priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> queue(
        //         [](ListNode *a, ListNode *b) {
        //             return a->val > b->val;
        //         });

        // 自定义比较函数，用于最小堆
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // 将每个链表的头节点加入最小堆
        for (const auto element: lists) {
            minHeap.push(element);
        }

        while (!minHeap.empty()) {
            ListNode *node = minHeap.top();
            minHeap.pop();

            p->next = node;
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }

            p = p->next;
        }
        return dummy.next;
    }
};

