//
// Created by darion.yaphet on 2025/5/3.
//

#include "TreeNode.h"
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/increasing-order-search-tree/
class Solution {
public:
    // 树中最左边的节点成为树的根节点。
    // 每个节点只有右子节点，没有左子节点。
    TreeNode *increasingBST(TreeNode *root) {
        // 创建一个虚拟节点作为链表的起始点
        TreeNode dummy(0);
        prev = &dummy;

        // 中序遍历构造新的树
        inorder(root);

        // 返回新树的根节点（即虚拟节点的右子节点）
        return dummy.right;
    }

    // 中序遍历并构造新的树
    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        // 递归遍历左子树
        inorder(node->left);

        // 修改当前节点
        prev->right = node; // 将当前节点作为 prev 的右子节点
        node->left = nullptr; // 清空左子节点
        prev = node; // 更新 prev 为当前节点

        // 递归遍历右子树
        inorder(node->right);
    }

private:
    TreeNode *prev; // 用于记录当前链表的最后一个节点
};

// 测试代码
int main() {
    // 构造示例二叉搜索树
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    Solution solution;
    TreeNode *newRoot = solution.increasingBST(root);

    // 打印新树的结构
    TreeNode *curr = newRoot;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}
