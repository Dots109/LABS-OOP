#include "../include/Hex.hpp"

int main()
{
    Hex a("66101F");
    Hex b("616110");
    Hex c = a - b;
    std::cout << c;
}