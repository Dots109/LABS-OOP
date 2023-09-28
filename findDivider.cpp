#include <iostream>

int findDivider(int devider, int bound)  
{
    if(devider <= 0 || bound <= 0) {
        std::cout << "Please, enter the positive values.";
        return -1;
    }
    for(int i = bound ; i >= devider ; --i) {
        if(i % devider == 0) {
            std::cout << i;
            return i;
        }
    }
    std::cout << "There was no divider in the range :(";
    return -5;
}