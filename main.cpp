#include "./include/Binary.hpp"

int main() {
    Binary b(5);
    Binary b2(44);

    std::cout << b.toDecimal() << "\n";
    std::cout << b2.toDecimal() << "\n";
    std::cout << (b + b2).toDecimal() << "\n";
    std::cout << (b - b2).toDecimal() << "\n";

    std::cout << (b > b2) << "\n";
    std::cout << (b == b2) << "\n";
    std::cout << (b < b2) << "\n";
}