#pragma once

#include "./figure.h"

template <class T>
class Square;

template<typename T>
std::istream & operator>>(std::istream & stream, Square <T> & sq);

template <class T>
class Square final : public Figure<T>
{
public:
    Square();
    Square(const DArray<std::pair<T, T>> & points);
    Square(const std::initializer_list<std::pair<T, T>> & points);
    Square(const Square<T> & other) noexcept;
    Square(Square<T> && other) noexcept;

    friend std::istream & operator>> <>(std::istream & stream, Square&);

    ~Square() noexcept;

    std::pair<T, T> calculateGeomCentr() const;
    operator double() const;

    void operator=(const Square<T> & other);
    void operator=(Square<T> && other);

    bool operator==(const Square<T> & other) const;

private:
    bool checkValidPointsSquare(const DArray<std::pair<T, T>> & points);
};

#include "../src/square.cpp"