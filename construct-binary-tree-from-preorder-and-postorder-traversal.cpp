//
// Created by Chenguang Wang on 2024/2/19.
//

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        return build(preorder, 0, preorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &postorder, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // root 节点对应的值就是前序遍历数组的第一个元素
        int rootVal = preorder[preStart];

        // root.left 的值是前序遍历第二个元素
        // 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点
        // 确定 preorder 和 postorder 中左右子树的元素区间
        int leftRootVal = preorder[preStart + 1];

        // leftRootVal 在后序遍历数组中的索引
        int index = -1;
        for (int i = postStart; i <= postEnd; i++) {
            if (postorder[i] == leftRootVal) {
                index = i;
                break;
            }
        }

        // 左子树的元素个数
        int leftSize = index - postStart + 1;

        // 先构造出当前根节点
        TreeNode *root = new TreeNode(rootVal);
        // 递归构造左右子树
        // 根据左子树的根节点索引和元素个数推导左右子树的索引边界
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           postorder, postStart, index);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            postorder, index + 1, postEnd - 1);

        return root;
    }
};