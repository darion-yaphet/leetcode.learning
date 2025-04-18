//
// Created by Chenguang Wang on 2024/1/24.
//

#ifndef LEETCODE_LEARNING_LISTNODE_H
#define LEETCODE_LEARNING_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

#endif //LEETCODE_LEARNING_LISTNODE_H
