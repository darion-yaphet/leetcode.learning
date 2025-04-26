//
// Created by darion.yaphet on 2025/4/25.
//

#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/snapshot-array
class SnapshotArray {
private:
    // 存储每个索引的历史记录 (快照编号, 值)
    vector<vector<pair<int, int> > > history;
    int snap_id; // 当前快照编号

public:
    SnapshotArray(int length) : history(length), snap_id(0) {
    }

    // 设置指定索引的值
    void set(int index, int val) {
        // 如果当前索引已经有值且快照编号相同，则更新值
        if (!history[index].empty() && history[index].back().first == snap_id) {
            history[index].back().second = val;
        } else {
            // 否则，新增一条记录
            history[index].emplace_back(snap_id, val);
        }
    }

    // 获取快照并返回快照编号
    int snap() {
        return snap_id++;
    }

    // 获取快照并返回快照编号
    int get(int index, int snap_id) {
        const vector<pair<int, int> > &snapshots = history[index];
        // 二分查找找到不超过 snap_id 的最大快照编号
        int left = 0, right = snapshots.size() - 1, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (snapshots[mid].first <= snap_id) {
                result = snapshots[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

// 测试代码
int main() {
    SnapshotArray snapshotArr(3); // 初始化长度为 3 的快照数组

    snapshotArr.set(0, 5); // 设置索引 0 的值为 5
    cout << "Snap ID: " << snapshotArr.snap() << endl; // 快照 0

    snapshotArr.set(0, 6); // 设置索引 0 的值为 6
    cout << "Snap ID: " << snapshotArr.snap() << endl; // 快照 1

    cout << "Value at index 0, snap_id 0: " << snapshotArr.get(0, 0) << endl; // 输出 5
    cout << "Value at index 0, snap_id 1: " << snapshotArr.get(0, 1) << endl; // 输出 6

    return 0;
}
