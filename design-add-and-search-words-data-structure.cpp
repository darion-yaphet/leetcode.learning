//
// Created by darion.yaphet on 2025/8/13.
//

// https://leetcode.cn/problems/design-add-and-search-words-data-structure/

#include <iostream>
#include <unordered_map>
#include <string>

class WordDictionary {
private:
    // Trie节点结构
    struct TrieNode {
        std::unordered_map<char, TrieNode *> children; // 子节点映射
        bool isEndOfWord; // 标记是否为单词的结束

        TrieNode() : isEndOfWord(false) {
        }
    };

    TrieNode *root; // 根节点

public:
    // 初始化词典对象
    WordDictionary() {
        root = new TrieNode();
    }

    // 析构函数，释放内存
    ~WordDictionary() {
        destroyTrie(root);
    }

    // 递归释放Trie节点内存
    void destroyTrie(TrieNode *node) {
        if (node) {
            for (auto &pair: node->children) {
                destroyTrie(pair.second);
            }
            delete node;
        }
    }

    // 将单词添加到数据结构中
    void addWord(const std::string &word) {
        TrieNode *current = root;

        // 逐个字符遍历单词
        for (char c: word) {
            // 如果当前字符不在子节点中，创建新节点
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            // 移动到下一个节点
            current = current->children[c];
        }

        // 标记单词结束
        current->isEndOfWord = true;
    }

    // 搜索单词（支持通配符.）
    bool search(const std::string &word) {
        return searchHelper(word, 0, root);
    }

private:
    // 递归搜索辅助函数
    bool searchHelper(const std::string &word, int index, TrieNode *node) {
        // 如果已经遍历完所有字符
        if (index == word.length()) {
            return node->isEndOfWord; // 检查是否为完整单词的结束
        }

        char c = word[index];

        if (c == '.') {
            // 通配符情况：尝试所有可能的子节点
            for (auto &pair: node->children) {
                // 递归搜索剩余部分
                if (searchHelper(word, index + 1, pair.second)) {
                    return true;
                }
            }
            // 所有路径都搜索过但没找到
            return false;
        } else {
            // 普通字符：检查是否存在该字符的子节点
            if (node->children.find(c) != node->children.end()) {
                // 存在，继续搜索下一个字符
                return searchHelper(word, index + 1, node->children[c]);
            }
            // 不存在该字符的子节点
            return false;
        }
    }
};

// 使用示例和测试
int main() {
    WordDictionary wordDictionary;

    // 添加单词
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");

    // 测试搜索功能
    std::cout << "搜索 'pad': " << (wordDictionary.search("pad") ? "true" : "false") << std::endl; // false
    std::cout << "搜索 'bad': " << (wordDictionary.search("bad") ? "true" : "false") << std::endl; // true
    std::cout << "搜索 '.ad': " << (wordDictionary.search(".ad") ? "true" : "false") << std::endl; // true
    std::cout << "搜索 'b..': " << (wordDictionary.search("b..") ? "true" : "false") << std::endl; // true

    // 添加更多单词测试
    wordDictionary.addWord("leetcode");
    std::cout << "搜索 'le.tcode': " << (wordDictionary.search("le.tcode") ? "true" : "false") << std::endl; // true
    std::cout << "搜索 'le...ode': " << (wordDictionary.search("le...ode") ? "true" : "false") << std::endl; // true
    std::cout << "搜索 'le....de': " << (wordDictionary.search("le....de") ? "true" : "false") << std::endl; // false

    return 0;
}
