#include <iostream>

int findDivider(int devider, int bound)  
{
    if(devider <= 0 || bound <= 0) {
        throw std::range_error("");
    }
    for(int i = bound ; i >= devider ; --i) {
        if(i % devider == 0) {
            return i;
        }
    }
    throw std::range_error("");
}