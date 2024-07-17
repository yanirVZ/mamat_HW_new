#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char* name;
    int age;
    int id;
} Student;

Student* student_clone(const Student* original) {
    if (original == NULL) {
        return NULL;
    }

    //Allocate memory for the clone struct
    Student* clone = (Student*)malloc(sizeof(Student));
    if (clone == NULL) {
        return NULL;
    }

    //Allocate memory for the name string and copy it
    clone->name = (char*)malloc(strlen(original->name) + 1);
    if (clone->name == NULL) {
        free(clone);
        return NULL;
    }
    strcpy(clone->name, original->name);

    //Copy other fields
    clone->age = original->age;
    clone->id = original->id;

    return clone;
}

void student_destroy(Student* student) {
    if (student != NULL) {
        free(student->name); //Free the allocated name
        free(student);       //Free the allocated struct
    }
}

void student_print(const Student* student) {
    printf("student name: %s,age: %d,id: %d.\n",
        student->name, student->age, student->id);
}
