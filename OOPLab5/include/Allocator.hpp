#pragma once

#include <iostream>
#include <cstdint>
#include <vector>

template <typename T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    pointer allocate(size_type n);
    void deallocate(pointer ptr, size_type n);;

    template <class U>
    struct rebind 
    {
        using other = Allocator<U>;
    };

    template <typename... Args>
    void construct(pointer p, Args&& ...args);

    void destroy(pointer ptr);

private:
    std::vector<T* > _used_blocks;
};

#include "../src/Allocator.cpp"