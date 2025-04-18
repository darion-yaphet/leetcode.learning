//
// Created by Chenguang Wang on 2024/2/13.
//
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> elements;
    int capacity;
    int readIndex;
    int writeIndex;
public:
    MyCircularQueue(int k) {
        capacity = k + 1;
        elements = vector<int>(k + 1);
        readIndex = 0;
        writeIndex = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        elements[writeIndex] = value;
        writeIndex = (writeIndex + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        readIndex = (readIndex + 1) % capacity;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return elements[readIndex];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return elements[(writeIndex - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return readIndex == writeIndex;
    }

    bool isFull() {
        return ((writeIndex + 1) % capacity) == readIndex;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */