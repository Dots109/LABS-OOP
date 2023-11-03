#include "./header/square.h"
#include "./header/triangle.h"
#include "./header/octagon.h"
#include "./header/arrayFig.h"

int main()
{
    ArrayFig arr;

    Square sq;
    Triangle tr;
    Octagon oc;

    std::cout << "Enter a coordinates square" << std::endl;
    std::cin >> sq;
    std::cout << "Enter a coordinates triangle" << std::endl;
    std::cin >> tr;
    std::cout << "Enter a coordinates octagon" << std::endl;
    std::cin >> oc;

    arr.pushBack(&sq);
    arr.pushBack(&tr);
    arr.pushBack(&oc);

    arr.printGeomCenters();
    arr.printAreas();
    std::cout << "Sum of areas figures: " << (double)arr << std::endl;

    std::cout << arr;

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
    
    return 0;
}