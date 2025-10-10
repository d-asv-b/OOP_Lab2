#pragma once

#include <iostream>
#include <cstddef>
#include <cstring>

#define MAX_SIZE (size_t)32

class Binary {
private:
    unsigned char data[MAX_SIZE];
public:
    Binary();
    Binary(unsigned);

    Binary(const Binary&);

    Binary operator+(const Binary&) const;
    Binary operator-(const Binary&) const;

    bool operator>(const Binary&) const;
    bool operator<(const Binary&) const;
    bool operator==(const Binary&) const;

    Binary& operator=(const Binary&);

    unsigned toDecimal() const;
};