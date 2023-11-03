#include "../header/triangle.h"

Triangle::Triangle()
{
    std::vector<Coord> points;
    _points = points;
    _name = "Triangle";
}

Triangle::Triangle(const std::vector<Coord> & points)
{
    if (points.size() != 3) {
        throw std::length_error("Error! Triangle Constructor: invalid number of coordinates");
    } else if (!checkValidPointsTriangle(points)){
        throw std::invalid_argument("Error! Triangle Constructor: invalid points");
    } else {
        _points = points;
        _name = "Triangle";
    }
}

Triangle::Triangle(const Triangle & other) noexcept
{
    _points = other._points;
    _name = "Triangle";
}

Triangle::Triangle(Triangle && other) noexcept
{
    _points = other._points;
    other._name = "Triangle";
}

Triangle::~Triangle() noexcept
{
}

std::istream & operator>>(std::istream & stream, Triangle & tr)
{
    if (tr._points.size() != 0) {
        throw std::range_error("Error! operator>>: this Triangle already has points");
    } else {
        std::vector<Coord> points;
        Coord tmp;
        int numbOfTop = 3;
        for (size_t i = 0; i < numbOfTop; ++i) {
            std::cout << "Point " << i + 1 << " ";
            std::cout << "Enter Ox: ";
            stream >> tmp.x;
            std::cout << "\t";
            std::cout << "Enter Oy: ";
            stream >> tmp.y;

            points.push_back(tmp);
        }

        if (tr.checkValidPointsTriangle(points)) {
            tr._points = points;
        } else {
            throw std::length_error("Error! Triangle operator>>: invalid points");
        }
        
    }    

    return stream;
}

Coord Triangle::calculateGeomCentr() const
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

Triangle::operator double() const // Calculate area of Triangle
{
    double lenSide = this->calculateLengthOfSide();

    return ((pow(lenSide, 2) * sqrt(3)) / 4);
}

void Triangle::operator=(const Triangle & other)
{
    this->_points = other._points;
}

void Triangle::operator=(Triangle && other)
{
    this->_points = other._points;
}

bool Triangle::operator==(const Triangle & other) const
{
    if (this->calculateLengthOfSide() != other.calculateLengthOfSide()) {
        return false;
    }

    return true;
}

bool Triangle::checkValidPointsTriangle(const std::vector<Coord> & points)
{
    bool allSidesEqual = true; 

    for (size_t i = 0; i < points.size(); ++i) {
        int nextIndex = (i + 1) % 3;
        double sideLength1 = (sqrt(pow(points[nextIndex].x - points[i].x, 2) +
                                 pow(points[nextIndex].y - points[i].y, 2)));
        double sideLength2 = (sqrt(pow(points[(nextIndex + 1) % 3].x - points[nextIndex].x, 2) +
                                 pow(points[(nextIndex + 1) % 3].y - points[nextIndex].y, 2)));
        
        if ((round(sideLength1) != round(sideLength2)) &&
            (!(abs(sideLength1 - sideLength2) < EPS) &&
            !(abs(sideLength2 - sideLength1) < EPS))) {
                
            allSidesEqual = false; 
            break;
        }
    }

    return allSidesEqual;   
}