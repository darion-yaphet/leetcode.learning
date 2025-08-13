//
// Created by darion.yaphet on 2025/6/30.
//

#include <iostream>

class Singleton {
public:
    // 获取单例实例的接口函数
    static Singleton &getInstance() {
        static Singleton instance; // 局部静态变量，线程安全（C++11后）
        return instance;
    }

    // 删除拷贝构造和赋值操作，防止复制
    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

    void doSomething() {
        std::cout << "Singleton is doing something." << std::endl;
    }

private:
    // 构造函数私有化
    Singleton() {
        // 初始化代码
    }

    ~Singleton() {
        // 清理资源（如果需要）
    }
};

// 使用示例
int main() {
    Singleton &s = Singleton::getInstance();
    s.doSomething();
    return 0;
}
