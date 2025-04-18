//
// Created by Chenguang Wang on 2024/2/19.
//

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }

    TreeNode *build(vector<int> &inorder, int inStart, int inEnd,
                    vector<int> &postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootValue = postorder[postEnd];

        int index = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootValue) {
                index = i;
                break;
            }
        }

        int leftSize = index - inStart;

        TreeNode *root = new TreeNode(rootValue);
        root->left = build(inorder, inStart, index - 1,
                           postorder, postStart, postStart + leftSize - 1);
        root->right = build(inorder, index + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1);
        return root;
    }
};