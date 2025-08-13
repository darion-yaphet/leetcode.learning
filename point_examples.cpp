//
// Created by darion.yaphet on 2025/6/16.
//

#include <iostream>
#include <vector>
#include <algorithm>  // std::sort

using namespace std;

class Point {
private:
    int x, y;
    int *data; // 模拟资源分配

public:
    // 默认构造函数
    Point() : Point(0, 0) {
        cout << "Default Constructor called" << endl;
    }

    // 带参数的构造函数
    Point(int xVal, int yVal) : x(xVal), y(yVal), data(new int[10]) {
        for (int i = 0; i < 10; ++i)
            data[i] = i;
        cout << "Parameterized Constructor called" << endl;
    }

    // 转换构造函数（从 int 到 Point）
    explicit Point(int val) : Point(val, val) {
        cout << "Conversion Constructor called (int -> Point)" << endl;
    }

    // 拷贝构造函数
    Point(const Point &other) : x(other.x), y(other.y), data(new int[10]) {
        cout << "Copy Constructor called" << endl;
        for (int i = 0; i < 10; ++i)
            data[i] = other.data[i];
    }

    // 移动构造函数
    Point(Point &&other) noexcept
        : x(other.x), y(other.y), data(other.data) {
        cout << "Move Constructor called" << endl;
        other.data = nullptr;
    }

    // 拷贝赋值运算符
    Point &operator=(const Point &other) {
        cout << "Copy Assignment Operator called" << endl;
        if (this != &other) {
            delete[] data;

            x = other.x;
            y = other.y;
            data = new int[10];
            for (int i = 0; i < 10; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    // 移动赋值运算符
    Point &operator=(Point &&other) noexcept {
        cout << "Move Assignment Operator called" << endl;
        if (this != &other) {
            delete[] data;

            x = other.x;
            y = other.y;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~Point() {
        if (data != nullptr) {
            delete[] data;
            cout << "Destructor called, memory released." << endl;
        } else {
            cout << "Destructor called, no memory to release." << endl;
        }
    }

    // 友元声明
    friend ostream &operator<<(ostream &os, const Point &p);

    friend bool operator==(const Point &lhs, const Point &rhs);

    friend bool operator!=(const Point &lhs, const Point &rhs);

    friend bool operator<(const Point &lhs, const Point &rhs);

    friend bool operator>(const Point &lhs, const Point &rhs);

    friend bool operator<=(const Point &lhs, const Point &rhs);

    friend bool operator>=(const Point &lhs, const Point &rhs);
};

// 流输出运算符
ostream &operator<<(ostream &os, const Point &p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}

// == 运算符
bool operator==(const Point &lhs, const Point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

// != 运算符
bool operator!=(const Point &lhs, const Point &rhs) {
    return !(lhs == rhs);
}

// < 运算符（字典序）
bool operator<(const Point &lhs, const Point &rhs) {
    if (lhs.x < rhs.x) return true;
    if (lhs.x > rhs.x) return false;
    return lhs.y < rhs.y;
}

// > 运算符
bool operator>(const Point &lhs, const Point &rhs) {
    return rhs < lhs;
}

// <= 运算符
bool operator<=(const Point &lhs, const Point &rhs) {
    return !(rhs < lhs);
}

// >= 运算符
bool operator>=(const Point &lhs, const Point &rhs) {
    return !(lhs < rhs);
}

// 返回一个临时对象
Point createTempPoint() {
    Point temp(5, 10);
    return temp;
}

int main() {
    Point p1(2, 3);
    Point p2(2, 3);
    Point p3(3, 1);
    Point p4(1, 5);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;

    if (p1 <= p2)
        cout << p1 << " <= " << p2 << endl;

    if (p4 >= p1)
        cout << p4 << " >= " << p1 << endl;
    else
        cout << p4 << " < " << p1 << endl;

    // 使用 std::vector 和 std::sort 排序
    vector<Point> points = {p1, p3, p4, p2};
    sort(points.begin(), points.end());

    cout << "\nSorted Points:\n";
    for (const auto &p: points) {
        cout << p << endl;
    }

    return 0;
}
