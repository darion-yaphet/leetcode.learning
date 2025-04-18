//
// Created by Chenguang Wang on 2024/2/8.
//
#include<iostream>
#include<array>

using namespace std;

int main() {
    array<int, 8> myArr = {1, 3, 4, 6, 9};//固定大小为8
    cout << "myArr元素序列：";
    for (auto i = 0; i < 8; ++i) {
        cout << myArr[i] << " ";
    }
    cout << endl;

    array<int, 8> myArr1 = {2, 3, 4, 7, 8, 9};//固定大小为8
    cout << "myArr1元素序列：";
    for (auto i = 0; i < 8; ++i) {
        cout << myArr1[i] << " ";
    }
    cout << endl;

    myArr.swap(myArr1);   //交换两个容器的内容
    cout << "交换myArr与myArr1" << endl;
    cout << endl;

    cout << "myArr.at(3) = " << myArr.at(3) << endl;//任意访问
    cout << "myArr[3] = " << myArr[3] << endl;//任意访问
    cout << "myArr.front() = " << myArr.front() << endl;//获取第一个元素
    cout << "myArr.back() =  " << myArr.back() << endl;//获取最后一个元素
    cout << "myArr.data() = " << myArr.data() << endl;//获取第一个元素的指针
    cout << "*myArr.data() = " << *myArr.data() << endl;//获取第一个元素的指针指向的元素

    cout << "正向迭代器遍历容器：";
    for (auto it = myArr.begin(); it != myArr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    //逆向迭代器测试
    cout << "逆向迭代器遍历容器：";
    for (auto rit = myArr.rbegin(); rit != myArr.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    //正向常迭代器测试
    cout << "正向常迭代器遍历容器：";
    for (auto it = myArr.cbegin(); it != myArr.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    //逆向常迭代器测试
    cout << "逆向常迭代器遍历容器：";
    for (auto rit = myArr.crbegin(); rit != myArr.crend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    if (myArr.empty())
        cout << "myArr为空 " << endl;
    else
        cout << "myArr不为空 " << endl;
    cout << "myArr.size() = " << myArr.size() << endl;
    cout << "myArr.max_size() = " << myArr.max_size() << endl;

    return 0;
}