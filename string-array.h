#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include "GenericString.h"

class StringArray {
private:
    GenericString** strings;
    size_t capacity;
    size_t size;

public:
    StringArray();
    ~StringArray();

    void add(GenericString* str);
    size_t length() const;
    GenericString* get(size_t index) const;
};

#endif //STRING_ARRAY_H

