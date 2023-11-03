#include "../include/Hex.hpp"

Hex::Hex() {}

Hex::Hex(const std::string& num)
{
    size_t n = num.size();
    hex.resize(n);
    size_t j = n - 1;
    for(size_t i = 0 ; i < n  ; ++i) {
        if(num[j] >= '0' && num[j] <= '9') {
            hex[i] = num[j];
        }
        else if(num[j] >= 'A' && num[j] <= 'F') {
            hex[i] = num[j];
        }
        else {
            throw std::range_error("Invalid number");
        }
        --j;
    }
}

Hex::Hex(const size_t & n, const unsigned char &t) 
{
    if(t >= '0' && t <= '9') {
    }
    else if(t >= 'A' && t <= 'F') {
    }
    else {
        throw std::range_error("Invalid number");
    }
    this->hex.resize(n);
    for(size_t i = 0 ; i < n ; ++i) {
        hex[i] = t;
    }
}

Hex::Hex(Hex&& other) noexcept
{
    this->hex = std::move(other.hex);
}

Hex::Hex(const Hex& other)
{
    this->hex = other.hex;
}

Hex::Hex(const std::initializer_list<unsigned char> &t)
{
    hex.resize(t.size());
    int i = t.size();
    for (auto it = t.begin(); it != t.end() ; ++it) {
        unsigned char p = *it;
        --i;
        if(p >= '0' && p <= '9') {
            hex[i] = p;
        }
        else if(p >= 'A' && p <= 'F') {
            hex[i] = p;
        }
        else {
            throw std::range_error("Invalid number");
        }
    }
}

int Hex::hexToDecimal(char symb)
{
    if(symb >= '0' && symb <= '9') {
        return symb - '0';
    }
    else {
        return symb - 'A' + 10;
    }
}

char Hex::decimalToHex(int dec)
{
    if(dec >= 0 && dec <= 9) {
        return dec + '0';
    }
    else {
        return dec - 10 + 'A';
    }
}

Hex Hex::operator+(const Hex& other)
{
    int carry = 0;
    int i = 0;
    int sum = 0;
    Hex temp;
    int j = std::max(other.hex.size(), this->hex.size());
    temp.hex.resize(j);
    while(i < j) {
        if(i < other.hex.size()) {
            sum += hexToDecimal(other.hex[i]);
        }
        if(i < this->hex.size()) {
            sum += hexToDecimal(this->hex[i]);
        }
        sum += carry;
        carry = 0;
        if(sum >= 16) {
            carry = 1;
            sum %= 16;
        }
        temp.hex[i] = decimalToHex(sum);
        sum = 0;
        ++i;
    }
    if(carry) {
        temp.hex.push_back(carry + '0');
    }
    while(temp.hex.back() == '0' && temp.hex.size() > 1) {
        temp.hex.resize(temp.hex.size()-1);
    }
    return temp;
}

Hex Hex::operator-(const Hex& other)
{
    int takeUnit = 0;
    int i = 0;
    int sum = 0;
    int del2;
    int del1;
    Hex temp;

    if(*this < other) {
        throw std::range_error("negative value!");
    }

    int j = std::max(other.hex.size(), this->hex.size());
    while(i < j) {
        if(i < other.hex.size()) {
            del1 = hexToDecimal(other.hex[i]);
        }
        if(i < this->hex.size()) {
            del2 = hexToDecimal(this->hex[i]);
        }
        sum = del2 - del1 - takeUnit;
        takeUnit = 0;
        if(sum < 0 && i+1 != this->hex.size()) {
            takeUnit += 1;
            sum += 16;
        }
        temp.hex.push_back(decimalToHex(sum));
        ++i;
        sum = 0;
        del1 = 0;
        del2 = 0;
    }
    while(temp.hex.back() == '0' && temp.hex.size() > 1) {
        temp.hex.resize(temp.hex.size()-1);
    }
    return temp;
}

std::ostream &operator<<(std::ostream &out,  Hex &x) 
{
    for(long long int i = x.hex.size() - 1 ; i >= 0 ; --i) {
        out << x.hex[i];
    }
    return out;
}

void Hex::operator=(const Hex &other) 
{
    hex = other.hex;
}

bool Hex::operator>=(const Hex &r) const
{
    if(this->hex.size() < r.hex.size()) {
        return false;
    }
    else if(this->hex.size() > r.hex.size()) {
        return true;
    }
    else {
        for(long long int i = this->hex.size() - 1; i >= 0 ; --i) {
            if(this->hex.at(i) < r.hex.at(i)) {
                return false;
            }
            else if(this->hex.at(i) > r.hex.at(i)) {
                return true;
            }
        }
        return true;
    }
}

bool Hex::operator<=(const Hex &r) const
{
    if(this->hex.size() < r.hex.size()) {
        return true;
    }
    else if(this->hex.size() > r.hex.size()) {
        return false;
    }
    else {
        for(long long int i = this->hex.size() - 1 ; i >= 0 ; --i) {
            if(this->hex.at(i) > r.hex.at(i)) {
                return false;
            }
        }
        return true;
    }
}

bool Hex::operator<(const Hex &r) const 
{
    return !(*this >= r);
}

bool Hex::operator>(const Hex &r) const 
{
    return !(*this <= r);
}

bool Hex::operator==(const Hex &r) const 
{
    return this->hex == r.hex;
}

bool Hex::operator!=(const Hex &r) const 
{
    return this->hex != r.hex;
}

Hex::~Hex() noexcept 
{
}
 

