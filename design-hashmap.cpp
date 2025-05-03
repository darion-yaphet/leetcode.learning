//
// Created by darion.yaphet on 2025/5/3.
//

#include <vector>
#include <list>

using namespace std;

// https://leetcode.cn/problems/design-hashmap/

// 使用一个固定大小的数组作为桶（buckets），每个桶存储一个链表。
// 每个链表节点存储键值对 (key, value)。
// 通过哈希函数将键值对数组长度取模，得到桶的索引。
// 如果发生哈希冲突（不同的键映射到同一个桶），则在该桶中使用链表存储所有冲突的键值对。
class MyHashMap {
private:
    static const int BUCKET_SIZE = 1000; // 哈希表的桶数量
    vector<list<pair<int, int> > > buckets; // 每个桶是一个链表，存储 (key, value) 键值对

    // 哈希函数：将 key 映射到桶的索引
    int hash(int key) {
        return key % BUCKET_SIZE;
    }

public:
    MyHashMap() : buckets(BUCKET_SIZE) {
    }

    // 向 HashMap 插入一个键值对 (key, value)
    void put(int key, int value) {
        int index = hash(key);
        auto &bucket = buckets[index];

        // 查找是否已经存在 key
        for (auto &pair: bucket) {
            if (pair.first == key) {
                pair.second = value; // 更新值
                return;
            }
        }

        // 如果不存在，则插入新的键值对
        bucket.emplace_back(key, value);
    }

    // 返回特定的 key 所映射的 value；如果不存在，返回 -1
    int get(int key) {
        int index = hash(key);
        auto &bucket = buckets[index];

        // 在链表中查找 key
        for (const auto &pair: bucket) {
            if (pair.first == key) {
                return pair.second; // 返回值
            }
        }
        return -1; // 如果不存在，返回 -1
    }

    // 如果映射中存在 key 的映射，则移除 key 和它所对应的 value
    void remove(int key) {
        int index = hash(key);
        auto &bucket = buckets[index];

        // 查找并删除 key
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it); // 删除键值对
                return;
            }
        }
    }
};
