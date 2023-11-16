#include "./header/figure.h"
#include "./header/square.h"
#include "./header/triangle.h"
#include "./header/octagon.h"
#include "./header/functionDArray.h"

int main()
{
    //SQUARE
    // Coord s1 = {4, 4};
    // Coord s2 = {0, 4};
    // Coord s3 = {0, 0};
    // Coord s4 = {4, 0};

    //TRIANGLE
    // Coord t1 = {0, 1};
    // Coord t2 = {1, 0};
    // Coord t3 = {0.5, 2};

    //OCTAGON
    // Coord oc1 = {4, 3};
    // Coord oc2 = {3, 4};
    // Coord oc3 = {1, 4};
    // Coord oc4 = {0, 3};
    // Coord oc5 = {0, 1};
    // Coord oc6 = {1, 0};
    // Coord oc7 = {3, 0};
    // Coord oc8 = {4, 1};

    Square<double> sq;
    std::cout << "Enter square: " << std::endl;
    std::cin >> sq;
    Triangle<double> tr;
    std::cout << "Enter triangle: " << std::endl;
    std::cin >> tr;
    Octagon<double> oc;
    std::cout << "Enter octagon: " << std::endl;
    std::cin >> oc;
    
    DArray<Figure<double>*> array{&sq, &tr, &oc};
    printAllCoordArraysFigure(array);
    std::cout << "Sum of areas figures in array: " 
        << calcualteAllArea(array) << std::endl;
    printAllCoordGeomCenter(array);
    
    return 0;
}