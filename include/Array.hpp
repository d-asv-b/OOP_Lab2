#pragma once

#include <cstddef>
#include <cstring>

class Array {
private:
    // Указатель на динамический массив символов
    unsigned char* data_ptr = nullptr;

    // Размер массива
    size_t size = 0;
    size_t capacity = 0;
public:
    // Конструктор по умолчанию
    Array();
    // Конструктор с размером
    Array(size_t);
    // Конструктор с размером и значением по умолчанию
    Array(size_t, char);

    // Конструктор копирования
    Array(const Array&);
    // Конструктор перемещения
    Array(Array&&) noexcept;

    // Деструктор
    ~Array();

    // Оператор копирования
    Array& operator=(const Array&);
    // Оператор перемещения
    Array& operator=(Array&&) noexcept;

    // Операторы индексирования
    unsigned char& operator[](size_t idx);
    unsigned char operator[](size_t idz) const;

    // Метод получения размера
    size_t GetSize() const;

    // Методы добавления
    void PushBack(unsigned char);
    // Метод удаления
    unsigned char PopBack();
    
    // Метод очистки
    void Clear();
};
