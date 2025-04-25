//
// Created by darion.yaphet on 2025/4/25.
//

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// https://leetcode.cn/problems/clone-graph/
class Solution {
public:
    /**
     * 深拷贝意味着新图中的节点是全新的对象，而不是对原图节点的引用。
     * 图可能包含环，因此在克隆过程中需要记录已访问的节点以避免重复克隆。
     * 可以使用深度优先搜索（DFS）或广度优先搜索（BFS）来遍历图并克隆节点。
     */
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        return cloneNode(node);
    }

    Node *cloneGraph2(Node *node) {
        // 如果输入为空，直接返回空指针
        if (!node) {
            return nullptr;
        }

        // 哈希表用于存储已克隆的节点
        unordered_map<Node *, Node *> visited;

        // 使用队列进行广度优先搜索（BFS）
        queue<Node *> q;
        q.push(node);

        // 克隆起始节点
        Node *cloned = new Node(node->val);
        visited[node] = cloned;

        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();

            // 遍历当前节点的邻居
            for (Node *neighbor: cur->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // 如果邻居未被克隆，克隆它并加入队列
                    Node *clonedNeighbor = new Node(neighbor->val);
                    visited[neighbor] = clonedNeighbor;
                    q.push(neighbor);
                }

                // 将克隆的邻居添加到当前克隆节点的邻居列表中
                visited[cur]->neighbors.push_back(visited[neighbor]);
            }
        }

        return cloned; // 返回克隆后的根节点
    }

private:
    Node *cloneNode(Node *node) {
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        auto *cloned = new Node(node->val);
        visited[node] = cloned;

        for (auto *neighbor: node->neighbors) {
            cloned->neighbors.push_back(cloneNode(neighbor));
        }
        return cloned;
    }

    unordered_map<Node *, Node *> visited;
};
