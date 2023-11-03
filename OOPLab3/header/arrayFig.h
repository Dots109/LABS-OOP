#ifndef __ARRAYFIG_H__
#define __ARRAYFIG_H__

#include "figure.h"

class ArrayFig
{
public:
    ArrayFig();
    ~ArrayFig();
    friend std::ostream & operator<<(std::ostream & stream, const ArrayFig & arrFig);
    void pushBack(Figure* figure);
    void deleteToIndex(size_t index);
    
    size_t getSize();

    void printGeomCenters();
    void printAreas();
    operator double() const;
private:
    void printCoordGeomCentr(size_t index);

private:
    size_t _size = 0;
    size_t _capacity = 0;
    Figure** _array;
};

#endif // __ARRAYFIG_H__