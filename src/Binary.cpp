
#include "../include/Binary.hpp"

Binary::Binary() : Binary(0) {}

Binary::Binary(unsigned decimalNumber) {
    std::memset(this->data, 0, MAX_SIZE);

    size_t i = 0;
    while (decimalNumber > 0) {
        this->data[i] = decimalNumber & 1;

        decimalNumber >>= 1;
        ++i;
    }
}

Binary::Binary(const Binary& other) {
    std::memcpy(this->data, other.data, MAX_SIZE);
}

Binary Binary::operator+(const Binary& other) const {
    unsigned char carry = 0;
    Binary result;

    for (size_t i = 0; i < MAX_SIZE; ++i) {
        unsigned sum = this->data[i] + other.data[i] + carry;
        result.data[i] = sum % 2;
        carry = sum / 2;
    }

    return result;
}

Binary Binary::operator-(const Binary& other) const {
    unsigned char borrow = 0;
    Binary result;

    for (size_t i = 0; i < MAX_SIZE; ++i) {
        int subtraction = this->data[i] - borrow - other.data[i];
        if (subtraction >= 0) {
            result.data[i] = subtraction;
            borrow = 0;
        }
        else {
            result.data[i] = subtraction + 2;
            borrow = 1;
        }
    }

    return result;
}

bool Binary::operator==(const Binary& other) const {
    return std::memcmp(this->data, other.data, MAX_SIZE) == 0;
}

bool Binary::operator<(const Binary& other) const {
    for (int i = MAX_SIZE - 1; i >= 0; --i) {
        if (this->data[i] < other.data[i]) {
            return true;
        }
        else if (this->data[i] > other.data[i]) {
            return false;
        }
    }

    return false;
}

bool Binary::operator>(const Binary& other) const {
    return other < *this;
}

unsigned Binary::toDecimal() const {
    unsigned result = 0;

    for (size_t i = 0; i < MAX_SIZE; ++i) {
        if (data[i]) {
            result |= (1u << i);
        }
    }

    return result;
}