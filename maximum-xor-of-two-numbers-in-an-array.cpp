//
// Created by darion.yaphet on 2025/5/5.
//

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 异或运算的结果最大化的关键是让两个数的二进制表示在尽可能多的位上不同。
    // 使用一个字典树（Trie）存储所有数的二进制表示，并在插入每个数时，尝试找到与其异或结果最大的另一个数。
    // 字典树的深度对应于数字的二进制位数（从最高位到最低位），每个节点有两个子节点（0 和 1）。

    // 异或运算的性质：a⊕b=c 等价于 a⊕c=b。
    // 在遍历数组时，动态地构建一个前缀异或结果集合，并尝试找到与当前数异或结果最大的值。
    // 使用哈希表存储所有可能的前缀异或结果，以便快速查找。
    int findMaximumXOR(vector<int> &nums) {
        int maxResult = 0; // 最大异或结果
        int mask = 0; // 当前掩码，用于提取高位

        // 从最高位开始处理
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i); // 更新掩码，提取当前位及更高位
            unordered_set<int> prefixes; // 存储当前位的前缀异或结果

            // 将所有数的前缀加入哈希表
            for (int num: nums) {
                prefixes.insert(num & mask);
            }

            // 假设当前位可以为 1，尝试找到满足条件的两个前缀
            int candidate = maxResult | (1 << i); // 假设当前位为 1 的目标值

            for (int prefix: prefixes) {
                if (prefixes.count(prefix ^ candidate)) {
                    maxResult = candidate; // 如果找到，则更新最大异或结果
                    break;
                }
            }
        }

        return maxResult;
    }
};
