//
// Created by darion.yaphet on 2025/5/5.
//

#include "TreeNode.h"

#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/
class Solution {
public:
    // 使用深度优先搜索 (DFS) 构建一个从每个节点到其父节点的映射
    // 从目标节点开始进行广度优先搜索 (BFS) ，逐层向外扩展，直到达到距离 k。
    // 在 BFS 过程中，记录访问过的节点以避免重复访问。
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        // 构建父节点映射
        unordered_map<TreeNode *, TreeNode *> parentMap;
        buildParentMap(root, nullptr, parentMap);

        // 广度优先搜索找到距离为 k 的节点
        vector<int> result;
        unordered_set<TreeNode *> visited; // 记录访问过的节点

        queue<TreeNode *> q;
        q.push(target);
        visited.insert(target);

        int currentDistance = 0;
        while (!q.empty()) {
            int size = q.size();
            if (currentDistance == k) {
                for (int i = 0; i < size; ++i) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }

            // 遍历当前层的节点
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();

                // 向左子节点扩展
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                // 向右子节点扩展
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                // 向父节点扩展
                if (parentMap[node] && visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }

            // 增加当前距离
            ++currentDistance;
        }
        return result;
    }

    void buildParentMap(TreeNode *node,
                        TreeNode *parent,
                        unordered_map<TreeNode *, TreeNode *> &parentMap) {
        if (node == nullptr) {
            return;
        }

        parentMap[node] = parent;
        buildParentMap(node->left, node, parentMap);
        buildParentMap(node->right, node, parentMap);
    }
};
