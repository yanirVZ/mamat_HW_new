#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_input(FILE* f, int** grades, int* num_grades);
int compare(const void* a, const void* b);
double calculate_median(int* grades, int num_grades);

int main(int argc, char* argv[]) {
    FILE* f = stdin;
    int* grades = NULL;
    int num_grades = 0;

    if (argc > 1 && strcmp(argv[1], "-") != 0) {
        f = fopen(argv[1], "r");
        if (f == NULL) {
            perror("Error opening file");
            return 1;
        }
    }

    process_input(f, &grades, &num_grades);

    if (f != stdin) {
        fclose(f);
    }

    if (num_grades > 0) {
        int median = calculate_median(grades, num_grades);
        printf("%d\n", median);
    }
    else {
        printf("No grades found.\n");
    }

    free(grades);

    return 0;
}

void process_input(FILE* f, int** grades, int* num_grades) {
    int capacity = 10;
    *grades = malloc(capacity * sizeof(int));
    if (*grades == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    int grade;
    int line_num = 0;
    *num_grades = 0;
    while (fscanf(f, "%d", &grade) != EOF) {
        line_num++;

        if (grade < 0 || grade > 100) {
            fprintf(stderr, "Error at line %d: grade %d invalid\n", line_num, grade);
            free(*grades);
            exit(1);
        }

        if (*num_grades >= capacity) {
            capacity *= 2;
            *grades = realloc(*grades, capacity * sizeof(int));
            if (*grades == NULL) {
                perror("Memory reallocation failed");
                exit(1);
            }
        }
        (*grades)[(*num_grades)++] = grade;
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double calculate_median(int* grades, int num_grades) {
    qsort(grades, num_grades, sizeof(int), compare);

    int median_index = (num_grades + 1) / 2 - 1;
    return grades[median_index];
}
