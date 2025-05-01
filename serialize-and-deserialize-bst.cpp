//
// Created by darion.yaphet on 2025/5/1.
//

#include "TreeNode.h"

#include <string>
#include <vector>
#include <sstream>

using namespace std;

// https://leetcode.cn/problems/serialize-and-deserialize-bst/
class Codec {
public:
    /*
     * 左子树的所有节点值小于当前节点值。
     * 右子树的所有节点值大于当前节点值。
     *
     * 可以通过前序遍历或后序遍历来序列化二叉搜索树，并在反序列化时根据排序规则重建树结构。
     */

    // Encodes a tree to a single string.
    // 使用前序遍历（根 -> 左 -> 右）将节点值按顺序写入字符串。
    string serialize(TreeNode *root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        // 空字符串表示空树
        if (data.empty()) {
            return nullptr;
        }

        istringstream in(data);
        vector<int> values; // 存储所有节点值
        string val;

        // 解析字符串中的节点值
        while (getline(in, val, ',')) {
            values.push_back(stoi(val));
        }

        // 根据前序遍历结果和 BST 性质重建树
        return deserializeHelper(values, 0, values.size() - 1);
    }

private:
    // 前序遍历序列化
    void serializeHelper(TreeNode *node, ostringstream &out) {
        // 空节点不存储
        if (!node) {
            return;
        }

        out << node->val << ","; // 当前节点值
        serializeHelper(node->left, out); // 递归处理左子树
        serializeHelper(node->right, out); // 递归处理右子树
    }

    // 根据前序遍历结果重建 BST
    TreeNode *deserializeHelper(const vector<int> &values, int start, int end) {
        // 空区间表示空树
        if (start > end) {
            return nullptr;
        }

        // 前序遍历的第一个值是根节点
        int rootVal = values[start];
        TreeNode *root = new TreeNode(rootVal);

        // 找到左右子树的分界点
        int splitIndex = end + 1; // 默认右子树为空
        for (int i = start + 1; i <= end; ++i) {
            if (values[i] > rootVal) {
                // 右子树开始的位置
                splitIndex = i;
                break;
            }
        }

        // 递归构建左子树和右子树
        root->left = deserializeHelper(values, start + 1, splitIndex - 1);
        root->right = deserializeHelper(values, splitIndex, end);
        return root;
    }
};
