#include "./include/Binary.hpp"

int main() {
    Binary b(124);
    Binary b2(44);

    std::cout << b.toDecimale() << "\n";
    std::cout << b2.toDecimale() << "\n";
    std::cout << (b + b2).toDecimale() << "\n";
    std::cout << (b - b2).toDecimale() << "\n";

    std::cout << (b > b2) << "\n";
    std::cout << (b == b2) << "\n";
    std::cout << (b < b2) << "\n";
}