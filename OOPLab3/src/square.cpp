#include "../header/square.h"

Square::Square()
{
    std::vector<Coord> points;
    _points = points;
    _name = "Square";
}

Square::Square(const std::vector<Coord> & points)
{
    if (points.size() != 4) {
        throw std::length_error("Error! Square Constructor: invalid number of coordinates");
    } else if (!checkValidPointsSquare(points)){
        throw std::invalid_argument("Error! Square Constructor: invalid points");
    } else {
        _points = points;
        _name = "Square";
    }
}

Square::Square(const Square & other) noexcept
{
    _points = other._points;
    _name = "Square";
}

Square::Square(Square && other) noexcept
{
    _points = other._points;
    other._name = "Square";
}

Square::~Square() noexcept
{
}

std::istream & operator>>(std::istream & stream, Square & sq)
{
    if (sq._points.size() != 0) {
        throw std::range_error("Error! operator>>: this Square already has points");
    } else {
        std::vector<Coord> points;
        Coord tmp;
        int numbOfTop = 4;
        for (size_t i = 0; i < numbOfTop; ++i) {
            std::cout << "Point " << i + 1 << " ";
            std::cout << "Enter Ox: ";
            stream >> tmp.x;
            std::cout << "\t";
            std::cout << "Enter Oy: ";
            stream >> tmp.y;

            points.push_back(tmp);
        }

        if (sq.checkValidPointsSquare(points)) {
            sq._points = points;
        } else {
            throw std::length_error("Error! Square Constructor: invalid points");
        }
    }

    return stream;
}

Coord Square::calculateGeomCentr() const
{
    Coord tmp;

    for (size_t i = 0; i < _points.size(); ++i) {
        tmp.x += _points[i].x;
        tmp.y += _points[i].y;
    }

    tmp.x /= _points.size();
    tmp.y /= _points.size();

    return tmp;
}

Square::operator double() const // Calculate area of Square
{
    return pow(this->calculateLengthOfSide(), 2); 
}

void Square::operator=(const Square & other)
{
    this->_points = other._points;
}

void Square::operator=(Square && other)
{
    this->_points = other._points;
}

bool Square::operator==(const Square & other) const
{
    if (this->calculateLengthOfSide() != other.calculateLengthOfSide()) {
        return false;       
    }

    return true;
}

bool Square::checkValidPointsSquare(const std::vector<Coord> & points)
{
    bool allSidesEqual = true;
    bool allAnglesRight = true;

    for (int i = 0; i < 4; i++) {
        int nextIndex = (i + 1) % 4;
        double sideLength1 = (sqrt(pow(points[nextIndex].x - points[i].x, 2) +
                                 pow(points[nextIndex].y - points[i].y, 2)));
        double sideLength2 = (sqrt(pow(points[(nextIndex + 1) % 4].x - points[nextIndex].x, 2) +
                                 pow(points[(nextIndex + 1) % 4].y - points[nextIndex].y, 2)));

        double angle1 = atan2(points[nextIndex].y - points[i].y,
                                 points[nextIndex].x - points[i].x);
        double angle2 = atan2(points[nextIndex + 1].y - points[nextIndex].y,
                                 points[nextIndex + 1].x - points[nextIndex].x);

        if ((!(abs(sideLength2 - sideLength1) < EPS)) && (!(fabs(angle1 - angle2) < EPS))) {
            allSidesEqual = false;
            break;
        }


    }

    return allSidesEqual ;
}