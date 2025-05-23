//
// Created by Chenguang Wang on 2024/1/19.
//

// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/

#include "Node.h"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }

        vector<vector<int>> result;
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                Node *node = queue.front();
                queue.pop();

                v.emplace_back(node->val);

                for (auto & n : node->children) {
                    if (n != nullptr) {
                        queue.emplace(n);
                    }
                }
            }
            result.emplace_back(std::move(v));
        }

        return result;
    }
};