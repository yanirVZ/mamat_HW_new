#include "string-array.h"

StringArray::StringArray() : strings(nullptr), capacity(0), size(0) {
    // Initialize the array
}

StringArray::~StringArray() {
    // Cleanup: delete allocated GenericString pointers and the array itself
    for (size_t i = 0; i < size; ++i) {
        delete strings[i];
    }
    delete[] strings;
}

void StringArray::add(GenericString* str) {
    if (size >= capacity) {
        // Perform resizing if necessary
        capacity = (capacity == 0) ? 1 : capacity * 2;
        GenericString** newStrings = new GenericString * [capacity];
        for (size_t i = 0; i < size; ++i) {
            newStrings[i] = strings[i];
        }
        delete[] strings;
        strings = newStrings;
    }
    strings[size++] = str;
}

size_t StringArray::length() const {
    return size;
}

GenericString* StringArray::get(size_t index) const {
    if (index < size) {
        return strings[index];
    }
    return nullptr; // or throw an exception for out-of-bounds access
}
