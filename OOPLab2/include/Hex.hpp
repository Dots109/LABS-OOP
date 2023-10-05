#ifndef HEX_HPP
#define HEX_HPP

#include <iostream>
#include "Vector.hpp"

class Hex
{
private:
    Vector<unsigned char> hex;
public:
    Hex();
    Hex(const std::string& num);
    Hex(const size_t & n, const unsigned char &t = 0);
    Hex(const Hex& other);
    Hex(Hex&& other) noexcept;
    Hex(const std::initializer_list<unsigned char> &t);

    virtual ~Hex() noexcept;

    int hexToDecimal(char symb);
    char decimalToHex(int dec);

    bool operator>=(const Hex &r) const;
    bool operator<=(const Hex &r) const;
    bool operator<(const Hex &r) const;
    bool operator>(const Hex &r) const;
    bool operator==(const Hex &r) const;
    bool operator!=(const Hex &r) const;
    void operator=(const Hex& other);
    Hex operator+(const Hex& other);
    Hex operator-(const Hex& other);

    friend std::ostream &operator<<(std::ostream &out,  Hex &x);
    friend std::istream &operator>>(std::istream &in,  Hex &x);
};


#endif //HEX_HPP
