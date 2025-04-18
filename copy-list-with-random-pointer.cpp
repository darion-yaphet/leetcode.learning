//
// Created by Chenguang Wang on 2024/2/14.
//

// https://leetcode.cn/problems/copy-list-with-random-pointer/description/

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<Node *, Node *> map;

public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (!map.count(head)) {
            Node *headNew = new Node(head->val);
            map[head] = headNew;

            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }

        return map[head];
    }
};