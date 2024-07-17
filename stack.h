#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "student.h"

typedef void* (*item_clone_fn)(void*);
typedef void (*item_destroy_fn)(void*);
typedef void (*item_print_fn)(void*);

typedef struct {
    void** items;
    int top;
    int max_size;
    item_clone_fn clone;
    item_destroy_fn destroy;
    item_print_fn print;
} Stack;


Stack* stack_create(int max_size, void* student_clone, void* student_destroy, void* student_print);
int stack_destroy(Stack* s);
int stack_push(Stack* s, void* new_item);
void stack_pop(Stack* s);
void* stack_peek(Stack* s);
int stack_size(Stack* s);
bool stack_is_empty(Stack* s);
int stack_capacity(Stack* s);
void stack_print(Stack* s);

#endif //Stack_H
