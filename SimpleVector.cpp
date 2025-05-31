//
// Created by darion.yaphet on 2025/5/25.
//

#include <iostream>
#include <memory>       // allocator, uninitialized_copy, move
#include <algorithm>    // copy, move
#include <vector>
#include <memory_resource>  // for unique_ptr test

template<typename T>
class SimpleVector {
private:
    T *elements = nullptr;
    size_t the_size = 0;
    size_t the_capacity = 0;
    std::allocator<T> alloc;

    // 工具方法：分配并构造新内存
    void alloc_n_copy(const T *src, size_t new_cap) {
        T *new_block = alloc.allocate(new_cap);
        try {
            for (size_t i = 0; i < the_size; ++i)
                std::allocator_traits<std::allocator<T> >::construct(alloc, new_block + i, src[i]);
        } catch (...) {
            for (size_t i = 0; i < the_size; ++i)
                std::allocator_traits<std::allocator<T> >::destroy(alloc, new_block + i);
            alloc.deallocate(new_block, new_cap);
            throw;
        }
        elements = new_block;
        the_capacity = new_cap;
    }

public:
    // 默认构造函数
    SimpleVector() = default;

    // 构造函数：指定大小
    explicit SimpleVector(size_t n) : the_size(n), the_capacity(n) {
        elements = alloc.allocate(n);
        for (size_t i = 0; i < n; ++i)
            std::allocator_traits<std::allocator<T> >::construct(alloc, elements + i);
    }

    // 拷贝构造函数
    SimpleVector(const SimpleVector &other) : the_size(other.the_size), the_capacity(other.the_capacity) {
        alloc_n_copy(other.elements, other.the_capacity);
    }

    // 移动构造函数
    SimpleVector(SimpleVector &&other) noexcept
        : elements(other.elements), the_size(other.the_size), the_capacity(other.the_capacity) {
        other.elements = nullptr;
        other.the_size = 0;
        other.the_capacity = 0;
    }

    // 拷贝赋值运算符
    SimpleVector &operator=(const SimpleVector &other) {
        if (this != &other) {
            SimpleVector tmp(other); // 复制构造
            swap(tmp); // 交换
        }
        return *this;
    }

    // 移动赋值运算符
    SimpleVector &operator=(SimpleVector &&other) noexcept {
        if (this != &other) {
            clear();
            alloc.deallocate(elements, the_capacity);

            elements = other.elements;
            the_size = other.the_size;
            the_capacity = other.the_capacity;

            other.elements = nullptr;
            other.the_size = 0;
            other.the_capacity = 0;
        }
        return *this;
    }

    ~SimpleVector() {
        clear();
        alloc.deallocate(elements, the_capacity);
    }

    // 获取大小
    size_t size() const { return the_size; }
    size_t capacity() const { return the_capacity; }

    bool empty() const { return the_size == 0; }

    // 下标访问
    T &operator[](size_t index) {
        return elements[index];
    }

    const T &operator[](size_t index) const {
        return elements[index];
    }

    // push_back（左值）
    void push_back(const T &value) {
        check_and_allocate();
        std::allocator_traits<std::allocator<T> >::construct(alloc, elements + the_size++, value);
    }

    // push_back（右值，支持移动）
    void push_back(T &&value) {
        check_and_allocate();
        std::allocator_traits<std::allocator<T> >::construct(alloc, elements + the_size++, std::move(value));
    }

    // 清空数据（但不释放内存）
    void clear() {
        for (size_t i = 0; i < the_size; ++i)
            std::allocator_traits<std::allocator<T> >::destroy(alloc, elements + i);
        the_size = 0;
    }

    // 改变大小
    void resize(size_t new_size) {
        if (new_size > the_capacity)
            reserve(std::max(new_size, the_capacity * 2));

        for (size_t i = the_size; i < new_size; ++i)
            std::allocator_traits<std::allocator<T> >::construct(alloc, elements + i); // 默认构造

        for (size_t i = new_size; i < the_size; ++i)
            std::allocator_traits<std::allocator<T> >::destroy(alloc, elements + i); // 析构多余部分

        the_size = new_size;
    }

    // 预留空间
    void reserve(size_t new_cap) {
        if (new_cap <= the_capacity)
            return;

        T *new_block = alloc.allocate(new_cap);
        try {
            for (size_t i = 0; i < the_size; ++i)
                std::allocator_traits<std::allocator<T> >::construct(alloc, new_block + i, std::move(elements[i]));
        } catch (...) {
            for (size_t i = 0; i < the_size; ++i)
                std::allocator_traits<std::allocator<T> >::destroy(alloc, new_block + i);
            alloc.deallocate(new_block, new_cap);
            throw;
        }

        for (size_t i = 0; i < the_size; ++i)
            std::allocator_traits<std::allocator<T> >::destroy(alloc, elements + i);
        alloc.deallocate(elements, the_capacity);

        elements = new_block;
        the_capacity = new_cap;
    }

    // 缩小容量到 size()
    void shrink_to_fit() {
        if (the_capacity == the_size)
            return;

        T *new_block = alloc.allocate(the_size);
        try {
            for (size_t i = 0; i < the_size; ++i)
                std::allocator_traits<std::allocator<T> >::construct(alloc, new_block + i, std::move(elements[i]));
        } catch (...) {
            for (size_t i = 0; i < the_size; ++i)
                std::allocator_traits<std::allocator<T> >::destroy(alloc, new_block + i);
            alloc.deallocate(new_block, the_size);
            throw;
        }

        for (size_t i = 0; i < the_size; ++i)
            std::allocator_traits<std::allocator<T> >::destroy(alloc, elements + i);
        alloc.deallocate(elements, the_capacity);

        elements = new_block;
        the_capacity = the_size;
    }

private:
    void check_and_allocate() {
        if (the_size == the_capacity)
            reserve(the_capacity ? the_capacity * 2 : 1);
    }

    void swap(SimpleVector &other) noexcept {
        std::swap(elements, other.elements);
        std::swap(the_size, other.the_size);
        std::swap(the_capacity, other.the_capacity);
        std::swap(alloc, other.alloc);
    }
};

int main() {
    SimpleVector<std::unique_ptr<int> > vec;

    vec.push_back(std::make_unique<int>(10));
    vec.push_back(std::make_unique<int>(20));
    vec.push_back(std::make_unique<int>(30));

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vec[" << i << "] = " << *vec[i] << std::endl;
    }

    vec.resize(5);
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i])
            std::cout << "vec[" << i << "] = " << *vec[i] << std::endl;
        else
            std::cout << "vec[" << i << "] is null" << std::endl;
    }

    vec.shrink_to_fit();

    return 0;
}
