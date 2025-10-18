#pragma once

#include <iostream>
#include <cstddef>
#include <cstring>

#include "Array.hpp"

#define MAX_SIZE (size_t)32

class Binary {
private:
    // Массив символов для хранения числа
    Array data;
public:
    // Конструктор по умолчанию
    Binary();
    // Конструктор из числа без знака
    Binary(unsigned);
    // Конструктор копирования
    Binary(const Binary&);
    // Конструктор перемещения
    Binary(Binary&&);

    // Оператор копирования
    Binary& operator=(const Binary&);
    // Оператор перемещения
    Binary& operator=(Binary&&) noexcept; 

    // Оператор сложения
    Binary operator+(const Binary&) const;
    // Оператор вычитание
    Binary operator-(const Binary&) const;

    // Операторы сравнения
    bool operator>(const Binary&) const;
    bool operator<(const Binary&) const;
    bool operator==(const Binary&) const;

    // Метод для получения десятичного представления числа
    unsigned toDecimal() const;
};