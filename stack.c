#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Stack {
    void** items;
    int max_size;
    int top;
} Stack;

Stack* stack_create(int max_size, void* student_clone,
    void* student_destroy, void* student_print) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == 0) //maybe NULL
    {
        return NULL;
    }
    stack->items = (void**)malloc(max_size * sizeof(void*));
    if (stack->items == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->max_size = max_size;
    return stack;
}


int stack_destroy(Stack* s) {
    if (s != NULL) {
        free(s->items);
        free(s);
        return 0;
    }
    return -1;
}

int stack_push(Stack* s, void* new_item) {
    if (s == NULL) {
        return 1; // Stack does not exist
    }

    if (s->top >= s->max_size - 1) {
        return 1; // Stack is full
    }

    s->items[++s->top] = new_item;

    return 0;
}


void stack_pop(Stack* s) {
    if (s->top == -1) {
        return;
    }
    s->top--;
}

void* stack_peek(Stack* s) {
    if (s->top == -1) {
        return NULL;
    }
    return s->items[s->top];
}

int stack_size(Stack* s) {
    return s->top + 1;
}

bool stack_is_empty(Stack* s) {
    return s->top == -1;
}

int stack_capacity(Stack* s) {
    return s->max_size - (s->top + 1);
}

void stack_print(Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%p\n", s->items[i]);
    }
}
