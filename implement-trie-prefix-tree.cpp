//
// Created by darion.yaphet on 2025/8/9.
//

// https://leetcode.cn/problems/implement-trie-prefix-tree/

#include <string>

using namespace std;

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie {
private:
    // Trie 节点定义
    struct TrieNode {
        vector<TrieNode *> children; // 子节点数组，索引对应字符
        bool isEnd; // 标记是否为单词的结束

        // 构造函数
        TrieNode() {
            children.resize(26, nullptr); // 26 个小写英文字母
            isEnd = false;
        }
    };

    TrieNode *root; // 根节点

public:
    // 构造函数：初始化 Trie
    Trie() {
        root = new TrieNode();
    }

    // 向 Trie 中插入单词
    void insert(string word) {
        TrieNode *current = root;

        // 逐个字符处理
        for (char c: word) {
            int index = c - 'a'; // 将字符转换为索引 (a->0, b->1, ...)

            // 如果该字符对应的子节点不存在，创建新节点
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }

            // 移动到下一个节点
            current = current->children[index];
        }

        // 标记单词结束
        current->isEnd = true;
    }

    // 搜索完整单词
    bool search(string word) {
        TrieNode *node = find(word);
        // 只有当节点存在且标记为单词结束时才返回 true
        return node != nullptr && node->isEnd;
    }

    // 检查是否存在以 prefix 开头的单词
    bool startsWith(string prefix) {
        // 只需要找到该前缀对应的节点即可
        return find(prefix) != nullptr;
    }

private:
    // 辅助函数：查找字符串对应的节点
    TrieNode *find(const string &str) {
        TrieNode *current = root;

        for (char c: str) {
            int index = c - 'a';

            // 如果路径中断，说明不存在
            if (current->children[index] == nullptr) {
                return nullptr;
            }

            current = current->children[index];
        }

        return current; // 返回最终到达的节点
    }
};

// 测试代码
int main() {
    Trie trie;

    // 测试插入
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");

    // 测试搜索
    cout << "search('apple'): " << (trie.search("apple") ? "true" : "false") << endl; // true
    cout << "search('app'): " << (trie.search("app") ? "true" : "false") << endl; // true
    cout << "search('appl'): " << (trie.search("appl") ? "true" : "false") << endl; // false
    cout << "search('application'): " << (trie.search("application") ? "true" : "false") << endl; // true

    // 测试前缀匹配
    cout << "startsWith('app'): " << (trie.startsWith("app") ? "true" : "false") << endl; // true
    cout << "startsWith('apl'): " << (trie.startsWith("apl") ? "true" : "false") << endl; // false
    cout << "startsWith('appl'): " << (trie.startsWith("appl") ? "true" : "false") << endl; // true

    return 0;
}
