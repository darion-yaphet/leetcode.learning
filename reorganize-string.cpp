//
// Created by Chenguang Wang on 2024/2/21.
//

// https://leetcode.cn/problems/reorganize-string

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        if (s.length() < 2) {
            return s;
        }

        vector counts(26, 0);
        int maxCount = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            char c = s[i];
            counts[c - 'a']++;
            maxCount = max(maxCount, counts[c - 'a']);
        }

        if (maxCount > (length + 1) / 2) {
            return "";
        }

        auto cmp = [&](const char &letter1, const char &letter2) {
            return counts[letter1 - 'a'] < counts[letter2 - 'a'];
        };

        priority_queue<char, vector<char>, decltype(cmp)> queue{cmp};
        for (char c = 'a'; c <= 'z'; c++) {
            if (counts[c - 'a'] > 0) {
                queue.push(c);
            }
        }

        string sb = "";
        while (queue.size() > 1) {
            char letter1 = queue.top();
            queue.pop();
            char letter2 = queue.top();
            queue.pop();
            sb += letter1;
            sb += letter2;

            int index1 = letter1 - 'a';
            int index2 = letter2 - 'a';
            counts[index1]--;
            counts[index2]--;

            if (counts[index1] > 0) {
                queue.push(letter1);
            }

            if (counts[index2] > 0) {
                queue.push(letter2);
            }
        }

        if (!queue.empty()) {
            sb += queue.top();
        }
        return sb;
    }

    string reorganizeString2(string s) {
        // 统计字符频率
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // 构建最大堆，按字符频率排序
        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        string result = "";
        pair<int, char> prev{-1, '#'}; // 记录上一次使用的字符及其频率

        while (!maxHeap.empty()) {
            auto current = maxHeap.top();
            maxHeap.pop();

            // 将当前字符添加到结果字符串
            result += current.second;

            // 减少当前字符的频率
            if (prev.first > 0) {
                maxHeap.push(prev); // 将之前的字符重新放回堆中
            }

            // 更新 prev 为当前字符及其剩余频率
            current.first--;
            prev = current;
        }

        // 如果结果字符串长度与原字符串长度不同，说明无法重新排列
        if (result.size() != s.size()) {
            return "";
        }

        return result;
    }
};
