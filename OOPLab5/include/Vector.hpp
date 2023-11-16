#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../include/Allocator.hpp"
#include <iostream>
#include <limits>
    
template<class T, class A = Allocator<T>>
class Vector
{
public:

class Iterator {
    private:
        Vector<T, A>& vector;
        size_t ind;
        friend class Vector<T, A>;
    public:

        Iterator(Vector &v, size_t i) : vector(v), ind(i) { }

        Iterator& operator++() {
            ++ind;
            return *this;
        }

        Iterator& operator--() {
            --ind;
            return *this;
        }

        T& operator*() {
            return vector[ind];
        }

        T* operator->() {
            return &vector[ind];
        }

        bool operator!=(const Iterator& other) const {
            if (ind != other.ind) return true;
            if (&vector != &(other.vector)) return true;
            return false;
        }

        bool operator==(const Iterator& other) const {
            if (ind != other.ind) return false;
            if (&vector != &(other.vector)) return false;
            return true;
        }
    };

class ConstIterator {
    private:
        Vector<T, A>& vector;
        size_t ind;
        friend class Vector<T, A>;
    public:

        ConstIterator(Vector &v, size_t i) : vector(v), ind(i) { }

        ConstIterator& operator++() {
            ++ind;
            return *this;
        }

        ConstIterator& operator--() {
            --ind;
            return *this;
        }

        T& operator*() {
            return vector[ind];
        }

        T& operator->() {
            return vector[ind];
        }

        bool operator!=(const ConstIterator& other) const {
            if (ind != other.ind) return true;
            if (&vector != &(other.vector)) return true;
            return false;
        }

        bool operator==(const ConstIterator& other) const {
            if (ind != other.ind) return false;
            if (&vector != &(other.vector)) return false;
            return true;
        }
    };


    Vector();
    Vector(size_t size, const T &value = T());
    Vector(const Vector &other);
    Vector(Vector &&other) noexcept;
    Vector(const std::initializer_list<T> &init);
    virtual ~Vector() noexcept;
    Vector<T> &operator=(const Vector<T> &other);
    void operator=(Vector<T, A> &&other);
    size_t CalculateCapacity(size_t newSize) const;
    void reallocate(size_t minSize);

    T &at(size_t pos);
    const T &at(size_t pos) const;
    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;
    T &back();
    const T &back() const;
    T *begin() noexcept;
    const T *begin() const noexcept;
    T *end() noexcept;
    const T *end() const noexcept;
    T *data() noexcept;
    const T *data() const noexcept;
    bool operator!=(const Vector<T, A> &rhs) const;
    bool operator==(const Vector<T, A> &rhs) const;
    bool operator>=(const Vector<T, A> &rhs) const;
    bool operator<=(const Vector<T, A> &rhs) const;
    bool operator>(const Vector<T, A> &rhs) const;
    bool operator<(const Vector<T, A> &rhs) const;

    void pop_back();
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t new_cap);
    void clear();
    void push_back(T &item);
    void push_back(T &&item);
    template<class... Args>
    void emplace_back(T &&arg, Args &&...args);
    void resize(size_t count);
    void resize(size_t count, const T &value);

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T *data_;
    Allocator<T> allocator_;
};

#include "../src/Vector.cpp"

#endif//VECTOR_HPP