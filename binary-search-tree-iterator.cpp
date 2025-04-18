//
// Created by Chenguang Wang on 2024/2/9.
//

// https://leetcode.cn/problems/binary-search-tree-iterator/description/

#include "TreeNode.h"
#include <vector>

using namespace std;

class BSTIterator {
private:
    void inorder(TreeNode *root, vector<int> &res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    vector<int> arr;
    int idx;

public:
    BSTIterator(TreeNode *root) : idx(0), arr(inorderTraversal(root)) {}

    int next() {
        return arr[idx++];
    }

    bool hasNext() {
        return (idx < arr.size());
    }

};
