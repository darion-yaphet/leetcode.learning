//
// Created by darion.yaphet on 2025/5/1.
//

#include "TreeNode.h"
#include <string>
#include <sstream>

using namespace std;

// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
class Codec {
public:
    /*
     * 使用前序遍历（Preorder Traversal）进行序列化和反序列化。
     * 在序列化过程中，用特殊字符（如 '#'）表示空节点，并用分隔符（如 ','）分隔节点值。
     * 在反序列化过程中，按照前序遍历的顺序重建二叉树。
     */

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    // 前序遍历序列化
    void serializeHelper(TreeNode *node, ostringstream &out) {
        if (node == nullptr) {
            out << "#,"; // 空节点用 '#' 表示
            return;
        }

        out << node->val << ","; // 当前节点值
        serializeHelper(node->left, out); // 递归处理左子树
        serializeHelper(node->right, out); // 递归处理右子树
    }

    // 前序遍历反序列化
    TreeNode *deserializeHelper(istringstream &in) {
        string val;
        getline(in, val, ','); // 读取下一个逗号分隔的值
        // 遇到空节点
        if (val == "#") {
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(val)); // 创建当前节点
        node->left = deserializeHelper(in); // 递归构建左子树
        node->right = deserializeHelper(in); // 递归构建右子树
        return node;
    }
};
