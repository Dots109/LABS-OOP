#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "figure.h"

class Square final : public Figure
{
public:
    Square();
    Square(const std::vector<Coord> & points);
    Square(const Square & other) noexcept;
    Square(Square && other) noexcept;

    ~Square() noexcept;

    friend std::istream & operator>>(std::istream & stream, Square & sq);
    
    Coord calculateGeomCentr() const override;
    operator double() const override;
    
    void operator=(const Square & other);
    void operator=(Square && other);

    bool operator==(const Square & other) const;

    bool checkValidPointsSquare(const std::vector<Coord> & points);
};

#endif // __SQUARE_H__