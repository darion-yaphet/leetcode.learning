//
// Created by Chenguang Wang on 2024/2/19.
//

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        int rootValue = preorder[preStart];

        int index = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootValue) {
                index = i;
                break;
            }
        }

        TreeNode *root = new TreeNode(rootValue);

        int leftSize = index - inStart;
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);
        return root;
    }
};