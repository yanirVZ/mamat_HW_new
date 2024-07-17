#include <stdio.h>
#include <stdlib.h>
#include "stack.h"  // Assuming your header file is named stack.h

// Define some example data structures or types you might want to store in the stack
typedef struct {
    int id;
    char name[50];
} Student;

// Example functions for cloning, destroying, and printing a Student
void* student_clone(void* item) {
    Student* original = (Student*)item;
    Student* cloned = (Student*)malloc(sizeof(Student));
    if (cloned != NULL) {
        cloned->id = original->id;
        strcpy(cloned->name, original->name);
    }
    return cloned;
}

void student_destroy(void* item) {
    free(item);
}

void student_print(void* item) {
    Student* student = (Student*)item;
    printf("ID: %d, Name: %s\n", student->id, student->name);
}

int main() {
    // Create a stack with a max size of 5
    Stack* stack = stack_create(5, student_clone, student_destroy, student_print);

    // Example students to push onto the stack
    Student s1 = { 1, "Alice" };
    Student s2 = { 2, "Bob" };
    Student s3 = { 3, "Charlie" };

    // Push some items onto the stack
    stack_push(stack, &s1);
    stack_push(stack, &s2);
    stack_push(stack, &s3);

    // Print the stack contents
    printf("Stack Contents:\n");
    stack_print(stack);

    // Pop an item from the stack
    stack_pop(stack);

    // Print the stack contents again
    printf("\nStack Contents after popping one item:\n");
    stack_print(stack);

    // Clean up and destroy the stack
    stack_destroy(stack);

    return 0;
}
