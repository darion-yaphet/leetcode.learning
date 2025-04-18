//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/

#include <vector>
#include <queue>

using namespace std;


class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        queue<Node *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }

        vector<vector<int>> result;
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> v;
            Node *node;
            Node *nodePre = nullptr;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    nodePre = queue.front();
                    queue.pop();
                    node = nodePre;
                } else {
                    node = queue.front();
                    queue.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }

                if (node->left != nullptr) {
                    queue.emplace(node->left);
                }

                if (node->right != nullptr) {
                    queue.emplace(node->right);
                }
            }
            nodePre->next = nullptr;
        }
        return root;
    }
};