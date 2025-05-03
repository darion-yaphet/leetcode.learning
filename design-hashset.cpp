//
// Created by darion.yaphet on 2025/5/3.
//

#include <vector>
#include <list>

using namespace std;

// https://leetcode.cn/problems/design-hashset/

// 使用一个固定大小的数组作为桶（buckets），每个桶存储一个链表。
// 通过哈希函数将键值映射到数组中的某个桶。
// 如果发生哈希冲突（不同的键映射到同一个桶），则在该桶中使用链表存储所有冲突的键。
class MyHashSet {
private:
    static const int BUCKET_SIZE = 1000; // 哈希表的桶数量
    vector<list<int> > buckets; // 每个桶是一个链表

    // 哈希函数：将 key 映射到桶的索引
    int hash(int key) {
        return key % BUCKET_SIZE;
    }

public:
    MyHashSet() : buckets(BUCKET_SIZE) {
    }

    void add(int key) {
        int index = hash(key);
        auto &bucket = buckets[index];
        // 如果 key 已经存在，则不插入
        for (int num: bucket) {
            if (num == key) {
                return;
            }
        }
        bucket.push_back(key); // 插入 key 到链表末尾
    }

    void remove(int key) {
        int index = hash(key);
        auto &bucket = buckets[index];

        // 查找并删除 key
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);
        auto &bucket = buckets[index];
        // 在链表中查找 key
        for (int num: bucket) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }
};
