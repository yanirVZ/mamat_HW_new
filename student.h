#ifndef STUDENT_H
#define STUDENT_H

typedef struct student {
    char* name;
    int age;
    int id;
}Student;

Student* student_clone(const Student* original);
void student_destroy(Student* student);
void student_print(const Student* student);


#endif