//
// Created by darion.yaphet on 2025/5/29.
//


class DataStream {
public:
    DataStream(int value, int k) {
        targetValue = value;
        requiredCount = k;
        count = 0;
    }

    bool consec(int num) {
        if (num == targetValue) {
            count += 1;
        } else {
            count = 0;
        }

        return count >= requiredCount;
    }

private:
    int targetValue;
    int requiredCount;
    int count; // 当前连续等于 targetValue 的次数
};
