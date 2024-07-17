#include<stdio.h>
#include<stdlib.h>
#include "linked-list.h"
#include "grades.h"
#include <stdbool.h>
#include <string.h>

typedef struct list *p_list;
typedef struct iterator *p_iterator; 

typedef struct Course
{
    int grade;
    char *name;
}course, *p_course ;

typedef struct Student
{
    char* student_name;
    int id;
    p_list courses;
    int course_num;
}student, *p_student;

typedef struct grades
{
  p_list students;
  int student_num;
}grades, *p_grades;

int clone_student(void *element, void **output);
void student_destroy(void *element);



/**
 * @brief Initializes the "grades" data-structure.
 * @returns A pointer to the data-structure, of NULL in case of an error
 */
struct grades* grades_init() 
{
    p_grades grades = (p_grades)malloc(sizeof(struct grades));
    if(grades == NULL)
    {
        return grades;
    }
    grades -> students = list_init(clone_student, student_destroy);
    if(grades -> students == NULL){
        grades_destroy(grades);
        return NULL;
    }
}





/**
 * @brief Destroys "grades", de-allocate all memory!
 */
void grades_destroy(struct grades *grades){




}









































/* struct grades* grades_init()
{
struct grades* new_grade = (struct grades*)malloc(sizeof(struct grades));
return new_grade;
}

void grades_destroy(struct grades *grades)
{
    if (grades != NULL)
    free(grades);
}

int grades_add_student(struct grades *grades, const char *name, int id);
{
     if (grades == NULL) {
        return -1;
    }
    struct grades* current = grades;
    while(current->next != NULL)
    {
        if(current->id == id)
        {
            return -1;
        }
        current = current->next;
    }
    struct grades* new_student = (struct grades*)malloc(sizeof(struct grades));
    if(new_student == NULL)
    {
        return -1;
    }
    

}
*/