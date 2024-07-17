#ifndef STRING_H
#define STRING_H

#include "generic-string.h"
#include "string-array.h" // Assuming StringArray is declared here

class String : public GenericString {
private:
    char* data; // Pointer to the actual string data
    size_t length; // Length of the string

public:
    // Constructors
    String();
    String(const String& s);
    String(const char* str);

    // Destructor
    ~String();

    // Assignment operators
    String& operator=(const String& s);
    String& operator=(const char* str);

    // Split method
    StringArray split(const char* delimiters) const;

    // Conversion methods
    int to_integer() const\;

    // Trim method
    String trim() const;

    // Virtual method from GenericString to return String&
    String& as_string() override { return *this; }
    const String& as_string() const override { return *this; }

};

#endif // STRING_H

