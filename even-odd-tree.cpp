//
// Created by darion.yaphet on 2025/5/5.
//

#include "TreeNode.h"

#include <queue>

using namespace std;

// https://leetcode.cn/problems/even-odd-tree/
class Solution {
public:
    bool isEvenOddTree(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode *> q;
        q.push(root);

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> values;

            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();

                values.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (level % 2 == 0) {
                for (int i = 0; i < values.size(); i++) {
                    if (values[i] % 2 == 0) {
                        return false;
                    }

                    if (i > 0 && values[i] <= values[i - 1]) {
                        return false;
                    }
                }
            } else {
                for (int i = 0; i < values.size(); i++) {
                    if (values[i] % 2 == 1) {
                        return false;
                    }

                    if (i > 0 && values[i] >= values[i - 1]) {
                        return false;
                    }
                }
            }

            level += 1;
        }
        return true;
    }
};
