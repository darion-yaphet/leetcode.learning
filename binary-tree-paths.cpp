//
// Created by Chenguang Wang on 2024/2/9.
//

#include "TreeNode.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        vector<int> path;
        internal(root, path, result);
        return result;
    }

    void internal(TreeNode *root, vector<int> &path, vector<string> &result) {
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            string p;
            int size = path.size();
            for (int i = 0; i < size - 1; i++) {
                p += to_string(path[i]);
                p += "->";
            }

            p += to_string(path[size - 1]);
            result.emplace_back(std::move(p));
        }

        if (root->left != nullptr) {
            internal(root->left, path, result);
            path.pop_back();
        }

        if (root->right != nullptr) {
            internal(root->right, path, result);
            path.pop_back();
        }
    }
};