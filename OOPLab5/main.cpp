#include "./include/Vector.hpp"


#include <map>
#include <unordered_map>
#include <iostream>


int main() {
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> a;
    a[0] = 1;
    a[1] = 2;
    for (const auto &p : a) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    Vector<int, Allocator<int>> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    for (const auto& i : b) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}