#include "../include/Allocator.hpp"

template <typename T>
template <typename... Args>
void Allocator<T>::construct(pointer p, Args&& ...args)
{
    new (p) T(std::forward<Args>(args)...);
}

template <typename T>
T* Allocator<T>::allocate(size_type n)
{
    T* ptr = (T*)(::operator new(sizeof(T) * n));
    _used_blocks.push_back(ptr);

    return ptr;
}

template <typename T>
void Allocator<T>::deallocate(pointer ptr, size_type n)
{
        delete (ptr);
}

template <typename T>
void Allocator<T>::destroy(pointer ptr)
{
    ptr->~T();
}