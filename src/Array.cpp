#include "../include/Array.hpp"
#include <cstddef>
#include <cstdlib>

Array::Array() { }

Array::Array(size_t size) {
    if (size > 0) {
        this->data_ptr = new char[size]();
        this->size = this->capacity = size;
    }
}

Array::Array(size_t size, char default_val) {
    if (size > 0) {
        this->data_ptr = new char[size];
        std::memset(this->data_ptr, default_val, size);

        this->size = this->capacity = size;
    }
}

Array::Array(const Array& other) {
    if (this != &other) {
        this->size = other.size;
        this->capacity = other.capacity;

        this->data_ptr = new char[this->capacity];
        std::memcpy(this->data_ptr, other.data_ptr, this->size);
    }
}

Array::Array(Array&& other) noexcept {
    if (this != &other) {
        this->data_ptr = other.data_ptr;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data_ptr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
}

Array::~Array() {
    delete[] this->data_ptr;
    this->data_ptr = nullptr;
    this->size = this->capacity = 0;
}

char& Array::operator[](size_t idx) {
    return this->data_ptr[idx];
}

char Array::operator[](size_t idx) const {
    return this->data_ptr[idx];
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] this->data_ptr;

        this->size = other.size;
        this->capacity = other.capacity;

        this->data_ptr = new char[this->capacity];
        std::memcpy(this->data_ptr, other.data_ptr, this->size);
    }

    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] this->data_ptr;

        this->data_ptr = other.data_ptr;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data_ptr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    return *this;
}

size_t Array::GetSize() const {
    return this->size;
}

void Array::PushBack(char val) {
    if (this->size + 1 > this->capacity) {
        this->capacity *= 2;
        
        char* new_mem = new char[this->capacity]();
        std::memcpy(new_mem, this->data_ptr, this->size);

        delete[] this->data_ptr;
        this->data_ptr = new_mem;
    }

    this->data_ptr[this->size] = val;
    ++this->size;
}

char Array::PopBack() {
    --this->size;
    return this->data_ptr[size];
}

void Array::Clear() {
    std::memset(this->data_ptr, 0, this->size);
    this->size = 0;
}