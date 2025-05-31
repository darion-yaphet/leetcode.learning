//
// Created by darion.yaphet on 2025/5/31.
//

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> seq1, seq2;
        collectLeaves(root1, seq1);
        collectLeaves(root2, seq2);
        return seq1 == seq2;
    }

private:
    void collectLeaves(TreeNode *node, vector<int> &sequence) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            sequence.push_back(node->val);
            return;
        }

        collectLeaves(node->left, sequence);
        collectLeaves(node->right, sequence);
    }
};
