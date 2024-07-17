#include "string.h"
#include "generic-string.h"
#include "cstring"
#include "cstdlib"
#include "iostream" 

#define SPACE ' '
/**
 * @brief Initiates an empty string
 */
String::String() {
    this->length = 0;
    this->data = new char[1];
    this->data[0] = '\0';
}

/**
 * @brief Initiates string from another string
 */
String::String(const String& s) {
    this->length = s.length;
    this->data = new char[this->length + 1];
    strcpy(this->data, s.data);
}

/**
 * @brief Initiates a string from a char array
 */
String::String(const char* str) {
    this->length = strlen(str);
    this->data = new char[this->length + 1];
    strcpy(this->data, str);
}

String::~String() {
    delete[] this->data;
}

StringArray String::split(const char* delimiters) const {
    StringArray result; // Create an instance of StringArray to store the split strings

    // Check if the data pointer is NULL or delimiters is NULL
    if (data == NULL || delimiters == NULL) {
        return result; // Return an empty StringArray if data or delimiters are NULL
    }

    // Create a temporary string to perform strtok operations
    char* str = new char[length + 1];
    strcpy(str, data);

    // Split the string using strtok
    char* token = strtok(str, delimiters);
    while (token != NULL) {
        // Add each token as a String to the StringArray
        result.add(String(token)); // Assuming String has a constructor from const char*

        token = strtok(NULL, delimiters);
    }

    delete[] str; // Free the temporary string memory
    return result; // Return the populated StringArray object
}

String::String operator=(const char* str){
    if (data != nullptr) {
        delete[] data; // Deallocate existing data if any
    }
    length = strlen(str); // Get length of the input string
    data = new char[length + 1]; // Allocate memory (+1 for /0)
    strcpy(data, str); // Copy the string into allocated memory

    return *this; //Return a reference to this object
}

/**
 * @brief Changes this from String
 */
String& String::operator=(const String& s) {
    if (this == &s) {
        return *this;
    }
    delete[] this->data;
    this->length = s.length;
    this->data = new char[this->length + 1];
    strcpy(this->data, s.data);
    return *this;
}
/**
 * @brief Converts the string to an integer
 */
int to_integer() const override {
    if (data == nullptr || strlen(data) == 0) {
        return -1; // Return false
    }
    return atoi(data); // Convert string data to integer
}

/**
 * @brief Removes leading and trailing whitespace from the string
 */
String String::trim() const {
    int start = 0;
    int end = length - 1;

    while (data[start] == SPACE) {
        start++;
    }

    while (data[end] == SPACE) {
        if (end == start) {
            return String(); // spaces string
        }
        end--;
    }
    end++;

    char trim_string[end - start + 1];//Allocate memory for the trimmed string
    strncpy(trim_string, &data[start], end - start);//Copy the trimmed string
    trim_string[end - start] = END_STRING;
    //trim_string = allocate_and_copy(&data[start],end-start);
    String new_trim_string = String(trim_string);
    return new_trim_string;

}


