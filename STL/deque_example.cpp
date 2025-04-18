//
// Created by Chenguang Wang on 2024/2/8.
//
#include<iostream>
#include<deque>

using namespace std;

int main() {
    deque<int> d;
    d.push_back(11);//在 deque 容器的末尾添加一个新元素
    d.push_back(20);
    d.push_back(35);
    cout << "初始化双端队列d：" << endl;
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << "\t";
    }
    cout << endl;

    d.push_front(10);//容器的开始位置插入一个新的元素，位于当前的第一个元素之前
    d.push_front(7);
    d.push_front(1);

    cout << "队列d向前陆续插入10、7、1:" << endl;
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << "\t";
    }
    cout << endl;

    d.pop_back(); //删除 deque 容器中的最后一个元素，有效地将容器大小减少一个
    d.pop_front(); //删除 deque 容器中的第一个元素，有效地减小其大小
    cout << "删除deque最后一个和第一个元素后:" << endl;
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << "\t";
    }
    cout << endl;
    return 0;
}