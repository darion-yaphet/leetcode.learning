//
// Created by darion.yaphet on 2024/11/5.
//

#include "ListNode.h"
#include "TreeNode.h"

// https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/description/
// 思路：
// 1. 找到链表的中点，将其断开，得到左子树和右子树。
// 2. 构造当前子树的根节点。
// 3. 递归构造左子树和右子树。
// 4. 返回根节点。

class Solution {
public:
    // 将链表转换为平衡二叉搜索树
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            // 空链表直接返回 nullptr
            return nullptr;
        }

        if (!head->next) {
            // 单节点链表直接返回根节点
            return new TreeNode(head->val);
        }

        // 第一步：找到链表的中点
        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 第二步：切割链表
        if (prev) {
            // 断开前半部分链表与后半部分的连接
            prev->next = nullptr;
        }

        // 第三步：构造当前子树的根节点
        TreeNode *root = new TreeNode(slow->val);

        // 第四步：递归构造左子树和右子树
        root->left = sortedListToBST(head); // 左半部分链表
        root->right = sortedListToBST(slow->next); // 右半部分链表

        return root;
    }
};
