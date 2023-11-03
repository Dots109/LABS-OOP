#ifndef __OCTAGON_H__
#define __OCTAGON_H__

#include "figure.h"

class Octagon final : public Figure
{
public:
    Octagon();
    Octagon(const std::vector<Coord> & points);
    Octagon(const Octagon & other) noexcept;
    Octagon(Octagon && other) noexcept;

    ~Octagon() noexcept;

    friend std::istream & operator>>(std::istream & stream, Octagon & sq);

    Coord calculateGeomCentr() const override;
    operator double() const override;

    void operator=(const Octagon & other);
    void operator=(Octagon && other);

    bool operator==(const Octagon & other) const;

private:
    bool checkValidPointsOctagon(const std::vector<Coord> & points);
};

#endif // __OCTAGON_H__