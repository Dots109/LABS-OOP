#include "../header/figure.h"

Figure::Figure()
{
    std::vector<Coord> points;
    _points = points;
}

Figure::Figure(const std::vector<Coord> & points) 
{
    _points = points;
}

Figure::~Figure() noexcept
{   
}

std::ostream & operator<<(std::ostream & stream, Coord coord)
{
    stream << "Ox: " << coord.x << " ";
    stream << "Oy: " << coord.y << std::endl;

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const Figure & fig)
{
    if (fig._points.size() == 0) {
        return stream << 0;
    }

    for (size_t i = 0; i < fig._points.size(); ++i) {
        stream << "Point " << i + 1 << "| ";
        stream << fig._points[i];
        
    }

    return stream;
}

std::istream & operator>>(std::istream & stream, Figure & fig)
{
    Coord tmp;
    std::cout << "Enter Ox: ";
    stream >> tmp.x;
    std::cout << "Enter Oy: ";
    stream >> tmp.y;
    
    fig._points.push_back(tmp);    

    return stream;
}

double Figure::calculateLengthOfSide() const
{
    return sqrt(pow(this->_points[0].x - this->_points[1].x, 2) + 
        pow(this->_points[0].y - this->_points[1].y, 2));
}

std::string Figure::getNameFigure() const
{
    return this->_name;
}
