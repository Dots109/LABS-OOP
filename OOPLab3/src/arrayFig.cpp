#include "../header/arrayFig.h"

ArrayFig::ArrayFig() : _size(0), _capacity(3)
{
    _array = new Figure*[_capacity];
}

ArrayFig::~ArrayFig()
{
    delete[] _array;
}

std::ostream & operator<<(std::ostream & stream, const ArrayFig & arrFig)
{
    for (size_t i = 0; i < arrFig._size; ++i) {
        stream << "   |" << "Figure #" << arrFig._array[i]->getNameFigure() << " |\n" <<
            *arrFig._array[i];
    }

    return stream;
}

void ArrayFig::printCoordGeomCentr(size_t index)
{
    std::string res;
    Coord c;
    
    c = this->_array[index]->calculateGeomCentr();
    
    std::cout << "Ox: " << c.x << " ";
    std::cout << "Oy: " << c.y << std::endl;
}

void ArrayFig::printGeomCenters()
{
    for (size_t i = 0; i < _size; ++i) {
        std::cout << "\n    | " << this->_array[i]->getNameFigure() << " center |\n";
        std::cout << "\t";
        this->printCoordGeomCentr(i);
    }
}

void ArrayFig::printAreas()
{
    for (size_t i = 0; i < _size; ++i) {
        std::cout << this->_array[i]->getNameFigure() << " area = " << double(*_array[i]) << std::endl;
    }
}

ArrayFig::operator double() const // Calculate area of all Array
{
    double result = 0;

    for (size_t i = 0; i < _size; ++i) {
        result += double(*_array[i]);
    }

    return result;
}

void ArrayFig::pushBack(Figure* figure) 
{
    if (_size >= _capacity) {
        _capacity *= 2;
        Figure** newArray = new Figure*[_capacity];
        
        for (size_t i = 0; i < _size; ++i) {
            newArray[i] = this->_array[i];
        }

        delete[] this->_array;
        this->_array = newArray;
    }

    this->_array[_size++] = figure;
}

void ArrayFig::deleteToIndex(size_t index)
{
    if (index < 0 || index >= _size) {
        throw std::range_error("Error! ArrayFig deleteToIndex: Invalid index for deletion.");
    }

    for (size_t i = index; i < _size - 1; ++i) {
        this->_array[i] = this->_array[i + 1]; // Копируем элементы сдвигая их на одну позицию назад
    }

    _size--;
}


size_t ArrayFig::getSize()
{
    return _size;
}