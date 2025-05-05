//
// Created by darion.yaphet on 2025/5/5.
//

#include "TreeNode.h"

#include <queue>

using namespace std;

class Solution {
public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode *> q;
        q.push(root);

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode *> nodes;

            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();

                nodes.push_back(node);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // 如果是奇数层，反转节点值
            if (level % 2 == 1) {
                int left = 0, right = nodes.size() - 1;
                while (left < right) {
                    std::swap(nodes[left]->val, nodes[right]->val);
                    left += 1;
                    right -= 1;
                }
            }
            level += 1;
        }
        return root;
    }
};
