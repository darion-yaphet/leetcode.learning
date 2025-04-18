//
// Created by Chenguang Wang on 2024/2/9.
//

#include "Node.h"

class Solution {
public:
    int maxDepth(Node *root) {
        if (root == nullptr) {
            return 0;
        }

        int max = 0;
        for (auto &n: root->children) {
            int depth = maxDepth(n);
            max = std::max(max, depth);
        }
        return max + 1;
    }
};
