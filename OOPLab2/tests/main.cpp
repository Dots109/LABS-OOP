#include "../include/Hex.hpp"

int main()
{
    Hex a("66101F");
    Hex b(std::move(a));
    std::cout << b << " " << a;;
}