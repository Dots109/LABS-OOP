#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "figure.h"

class Triangle final : public Figure
{
public:
    Triangle();
    Triangle(const std::vector<Coord> & points);
    Triangle(const Triangle & other) noexcept;
    Triangle(Triangle && other) noexcept;

    ~Triangle() noexcept;

    friend std::istream & operator>>(std::istream & stream, Triangle & tr);

    Coord calculateGeomCentr() const override;
    operator double() const override;

    void operator=(const Triangle & other);
    void operator=(Triangle && other);

    bool operator==(const Triangle & other) const; 

public:
    bool checkValidPointsTriangle(const std::vector<Coord> & points);
};

#endif //__TRIANGLE_H__